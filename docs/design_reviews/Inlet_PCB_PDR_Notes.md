# Inlet PCB – Notes and Action Items

## Clarified Notes

### Presentation / Documentation
- Move **block diagram** to the front of PDR slides.
- In future reviews, lead with **PCB review + system overview photo** up front.
- Plan an **interim review** (status check-in) that emphasizes tangible progress.

### Power & Reference
- Use the **same voltage reference (Vref)** for the ECU and the inlet PCB.
- Need **power requirements** and **idle speed data** from the mechanical team.

### H-Bridge Concerns
- Heat dissipation is a key risk — evaluate alternatives that handle more heat.
- Possible **rating exists for chip as runtime vs amperage** — research this.
- Consider **redundancy in H-bridge** for cooldown (maybe defer to later revisions).
- Add a **temperature sensor** near H-bridge to protect from overheating.
- Relate **current loading curve to H-bridge temperature** for thermal modeling.

### Mechanical Dependencies
- Get **cable run lengths** from test rig → important for noise & power delivery.
- Define **RPM measurement granularity** → mechanical requirement.
- Clarify **which inputs** from ME team are still pending.
- Identify **absolute ME requirements** that are critical for PCB work.
- Obtain **UI requirements** from ME team.
- Add **large engine milestones** from ME team into master schedule.

### Testing & Prototyping
- Set up a **wet bench with plexiglass enclosure** or simple test rig.
- Build a **rotor test apparatus** for motor + RPM sensor validation.
- Consider **brushless motor for startup** as an alternate design path.
- **Startup sequence may be trial-and-error** → define adjustable parameters and ensure they are accessible via UI.
- Collect data into **CSV format** for parsing and analysis.

### Research
- Look at **other engines** for design reference and benchmarking.

---

## Actionable Items

### Presentation & Process
- [ ] Move block diagram to **front of PDR slides**.
- [ ] Add **system overview + PCB review** to next review’s intro.
- [ ] Schedule **interim review** with tangible deliverables.

### Power & Reference
- [ ] Standardize **Vref between ECU and inlet PCB**.
- [ ] Request **power requirements + idle speed** from ME team.

### H-Bridge
- [ ] Research **backup H-bridge boards** with higher thermal tolerance.
- [ ] Look up **chip runtime vs amperage ratings**.
- [ ] Add **temp sensor** to H-bridge design.
- [ ] Develop **current load vs temp curve** for H-bridge.

### Mechanical Integration
- [ ] Get **cable run lengths + noise considerations** from ME team.
- [ ] Request **RPM granularity requirement** from ME team.
- [ ] Identify **critical ME requirements** needed now.
- [ ] Get **UI requirements** from ME team.
- [ ] Sync with ME team to integrate **large milestones** into project timeline.

### Testing
- [ ] Build **wet bench setup** with plexiglass enclosure.
- [ ] Plan and build **rotor test apparatus** for motor + RPM.
- [ ] Collect **CSV logging** for test data.

### Research / Alternative Paths
- [ ] Investigate **other engines** for design inspiration.
- [ ] Evaluate **brushless motor startup option**.

---

## Suggested Next Steps

**Immediate (This Week):**
- Move block diagram in slides.
- Request ME team inputs (power reqs, idle speed, cable lengths).
- Research H-bridge thermal ratings and backup options.

**Near-Term (Next 2 Weeks):**
- Set up wet bench test rig.
- Freeze Vref decision.
- Add temp sensor to schematic draft.

**Mid-Term (Next Month):**
- Rotor test apparatus ready.
- Collect first CSV test data.
- Interim review scheduled.
