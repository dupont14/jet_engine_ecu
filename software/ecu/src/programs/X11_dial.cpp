#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <unistd.h>
#include <fcntl.h>
#include <cmath>
#include <iostream>

#define PWM_PATH "/sys/class/pwm/pwmchip0/pwm0"
#define PERIOD_NS 20000000  // 20ms = 50Hz (servo-friendly)

void write_file(const char *path, int value)
{
    int fd = open(path, O_WRONLY);
    if (fd < 0) return;
    dprintf(fd, "%d", value);
    close(fd);
}

int main()
{
    // Initialize PWM
    write_file( "/sys/class/pwm/pwmchip0/export", 0)
    write_file(PWM_PATH "/period", PERIOD_NS);
    write_file(PWM_PATH "/enable", 1);

    Display *display = XOpenDisplay(nullptr);
    if (!display) {
        std::cerr << "Cannot open display\n";
        return 1;
    }

    int screen = DefaultScreen(display);
    Window window = XCreateSimpleWindow(
        display,
        RootWindow(display, screen),
        100, 100,
        300, 100,
        1,
        BlackPixel(display, screen),
        WhitePixel(display, screen)
    );

    XStoreName(display, window, "PWM Dial");
    XSelectInput(display, window, ExposureMask | ButtonPressMask | ButtonMotionMask);
    XMapWindow(display, window);

    GC gc = XCreateGC(display, window, 0, nullptr);

    int duty = PERIOD_NS / 2;

    while (true) {
        XEvent event;
        XNextEvent(display, &event);

        if (event.type == Expose) {
            XClearWindow(display, window);
            XDrawRectangle(display, window, gc, 20, 40, 260, 20);
            XFillRectangle(display, window, gc, 20, 40, (duty * 260) / PERIOD_NS, 20);
        }

        if (event.type == ButtonPress || event.type == MotionNotify) {
            int x = event.xbutton.x;
            if (x < 20) x = 20;
            if (x > 280) x = 280;

            duty = ((x - 20) * PERIOD_NS) / 260;
            write_file(PWM_PATH "/duty_cycle", duty);

            XClearWindow(display, window);
            XDrawRectangle(display, window, gc, 20, 40, 260, 20);
            XFillRectangle(display, window, gc, 20, 40, x - 20, 20);
        }
    }

    return 0;
}
