# Inlet PCB Team – Meeting Notes and Action Items  
**Date:** 10/20
**Sprint Duration:** 2 Weeks  

---

## Summary by Member

### Abigail
- Met with Professor Blinn to discuss ongoing Simulink modeling efforts.  
- Continuing work on system-level modeling to support ECU control logic validation.

**Action Items (Next 2 Weeks):**
- [ ] Refine Simulink model to simulate ECU–inlet PCB data exchange (SPI and PWM timing).  
- [ ] Coordinate with Ethan to align simulated SPI timing with actual embedded implementation.  
- [ ] Provide updated model results and diagrams for next meeting.

---

### Ethan
- Investigating SPI interface issue — currently receiving continuous zeros when no SPI transaction should be occurring.  
- Concerned that SPI clock synchronization may be downgrading the slave clock speed.

**Action Items (Next 2 Weeks):**
- [ ] Diagnose and correct SPI bus behavior (verify clock polarity, phase, and idle states).  
- [ ] Implement and test PWM signal generation for H-bridge control.  
- [ ] Document SPI timing diagrams for reference in next sprint review.

---

### Jeremy
- No progress reported this week.

**Action Items (Next 2 Weeks):**
- [ ] Begin reviewing inlet PCB schematic draft for layout readiness.  
- [ ] Assist with microcontroller selection validation and pinout review.  
- [ ] Support Ethan with SPI debugging (logic analyzer capture and documentation).

---

### Max
- Added simulated noise to signal; output confirmed clean.  
- Hall-effect sensor test apparatus has been constructed and will be tested today.

**Action Items (Next 2 Weeks):**
- [ ] Test new Hall-effect sensor performance using the completed test rig.  
- [ ] Implement ±5V signal amplification circuit and test output stability.  
- [ ] Identify a comparable **single-package SMD comparator** for integration on the PCB.  
- [ ] Explore feasibility of a **daughterboard-mounted H-bridge** for modular testing.

---

### Lucian
- To confirm motor selection and speed suitability with mechanical lead (Nolan).  

**Action Items (Next 2 Weeks):**
- [ ] Confirm motor specification (rated RPM, torque, startup current).  
- [ ] Update inlet PCB design parameters based on mechanical input (voltage, current limits).  
- [ ] Schedule next sprint review meeting and update master project milestone chart.

---

## General Team Goals (Next Sprint)
- [ ] Resolve SPI communication issues and verify stable bidirectional data transfer.  
- [ ] Complete preliminary H-bridge PWM testing and document voltage/current results.  
- [ ] Validate Hall-effect sensor accuracy using test apparatus.  
- [ ] Integrate key Simulink simulation findings into design documentation.  
- [ ] Review updated inlet PCB schematic before next milestone freeze.

---

**Next Meeting:** 10/27
**Focus Topics:**  
1. SPI communication validation results  
2. Hall-effect sensor test results  
3. H-bridge PWM signal test  
4. Simulink model correlation with physical system
