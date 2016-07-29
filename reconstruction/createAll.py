# Convenience script to call CreateData.C with many different inputs.
# CreateData requires the existance of an input/ directory to run:
# % mkdir input
# To use this script, you must first compile CreateData.C into a bin/ directory:
# % mkdir bin
# % g++ -O3 -o bin/CreateData CreateData.C -std=c++11 `root-config --cflags --glibs`
# % python createAll.py
import argparse
import os
import sys


# We only use combinations of NSAMPLE and NFREQ that give a total sampling
# period of 250 ns.
NSAMPLE_NFREQ = [ (10, 25), (20, 12.5), (40, 6.25) ]

# "CRRCXX" refers to a CR-RC pulse with time constant tau = XX.
# CRRC pulse shaping is compatible with all sampling rates.
CRRC_WF_NAMES = ["CRRC10", "CRRC20", "CRRC30", "CRRC43", "CRRC60", "CRRC90"]
WF_NFREQ_DICT = {wf : NSAMPLE_NFREQ for wf in CRRC_WF_NAMES}

# QIE refers to a "charge integrating and encoding" chip.
# Each simulated QIE response must be used with a specific sampling period.
# (QIE25: 25ns, QIE12: 12.5ns, QIE6: 6.25ns)
QIE_WF_NAMES = ["QIE25", "QIE12", "QIE6"]
WF_NFREQ_DICT.update(
    {wf : [NSAMPLE_NFREQ[i]] for i, wf in enumerate(QIE_WF_NAMES)})


def main(dryrun, nevents, waveform, amplitude, noise, npu, pufactor,
         pulse_shift, pileup_shift):
 
    for wf_name in waveform:
      for (n_sample, n_freq) in WF_NFREQ_DICT[wf_name]:
        for amp_val in amplitude:
          for noise_val in noise:
            for n_pileup in npu:
              for pu_factor in pufactor:
                for pulse_shift_val in pulse_shift:
                  for pileup_shift_val in pileup_shift:
                    toExec = "bin/CreateData %f %d %d %f %f %f %f %f %s %f" % (
                         pulse_shift_val, nevents, n_sample, n_freq, n_pileup,
                         amp_val, noise_val, pu_factor, wf_name, pileup_shift_val)
                    print toExec
                    if not dryrun:
                      os.system(toExec)


if __name__ == '__main__':
    p = argparse.ArgumentParser()

    p.add_argument('-d', '--dryrun', action='store_true')
    p.add_argument('-e', '--nevents', type=int,
                   default=1000)
    p.add_argument('-w', '--waveform', nargs="+", type=str,
                   default=CRRC_WF_NAMES+QIE_WF_NAMES,
                   choices=CRRC_WF_NAMES+QIE_WF_NAMES)
    p.add_argument('-a', '--amplitude', nargs="+", type=float,
                   default=[10.0])
    p.add_argument('-n', '--noise', nargs="+", type=float,
                   default=[0.0, 0.01, 0.02, 0.05, 0.1])
    p.add_argument('-p', '--npu', nargs="+", type=float,
                   default=[0.0])
    p.add_argument('-pf','--pufactor', nargs="+", type=float,
                   default=[1.0])
    p.add_argument('-sh','--pulse_shift', nargs="+", type=float,
                   default=[0.0])
    p.add_argument('-os','--pileup_shift', nargs="+", type=float,
                   default=[0.0])

    args = p.parse_args()

    main(**vars(args))
