Reconstruction step
====

Two steps:

    - create data with different pu, nsamples, nfreq, ...
    - run multifit

In the create step we can decide:

    - nPU : average number of pu (float)
    - NSAMPLES : number of sampled points out of the pulse
    - NFREQ: temporary space among points, in ns. nfreq must be defined such that the "in time" bunch crossing is one of it. e.g. 25 ns, 12.5 ns, 6.25 ns, ...
    - nEventsTotal: number of events to simulate
    - signalAmplitude: true signal amplitude of the interesting event.
    - pulse_shift: temporal shift of the simulated pulse relative to the simulated sampling. Useful to study the dependence on un-tracked temporal shifts of the pulse
    - pileup_shift: temporal shift of the simulated pileup events relative to the simulated sampling.
    - wf_name : name of the pulse shape. Used to construct the name of the file that stores the pulse shape waveform that CreaData uses as input.
    
Multifit need to know
    
    - NSAMPLES: how many points have been sampled
    - NFREQ: temporary space among points, in ns
    - wf_name : name of the pulse shape. Used to construct the name of the file that stores the pulse shape waveform that Multifit tries to fit to the data.

Multifit code will automatically assign the "active bunch crosses", under the assumption that there is a collision every 25 ns.


How to Create data
====

First compile:

    g++ -O3 -o bin/CreateData  CreateData.C -std=c++11 `root-config --cflags --glibs`

On Ubuntu, you may need to use extra linking flags:

    g++ -O3 -o bin/CreateData  CreateData.C -std=c++11 -Wl,--no-as-needed `root-config --ldflags --cflags --glibs`

Make a directory to hold the output from CreateData (which will be the input to multifit)

    mkdir input

Then
bin/CreateData <pulse_shift> <nEvents> <nSmpl> <nFreq> <nPU> <amplitudeTruth> <sigmaNoise> <puFactor> <wf_name> <pileup_shift>

The arguments are all optional because they have default values. However, they must be in the right order, so if you want to supply e.g. sigmaNoise, you have to specify everything that comes before it.

pulse_shift: float; default value = 0
time in ns that the event is "late" from when it is expected; this only really makes sense (the concept of "expecting") in the context of trying to reconstruct events

nEvents: int; default value = 1000
number of events to simulate

nSmpl: int; default value = 10
number of samples taken for each event

nFreq: float; default value = 25.0
sampling period in ns

nPU: int; default value = 0
average number of pileup events expected per event/per bunch crossing

amplitudeTruth: float; default value = 10.0
true energy of the event in GeV (where an "event" is an electron or photon hitting the detector)

sigmaNoise: float; default value = 0.044
average value of noise introduced by the electronics, in GeV

puFactor: float; default value = 1.0
factor to multiply the effect of each pileup event (I don't know why this is a thing....)

wf_name: string; default value = "CRRC43"
name of the pulse shape. This is used to form a filename that CreateData will use as input. CreateData will try to read from a file called
data/EmptyFile<wf_name>.root (in https://github.com/atishelmanch/vfe-toymc/tree/my-branch-atishelmanch/data ), so you can only use a wf_name if such a file exists or you will have problems. Currently the valid values for wf_name are "CRRC10", "CRRC20", "CRRC30", "CRRC43", "CRRC60", "CRRC90", "QIE6",  "QIE12.5", and "QIE25".

pileup_shift: float; default value = 0
time in ns that pileup events are later than expected (similar to the pulse_shift, which changes the time of the event "of interest" while this changes the time of the pileup events)

This will output a file

input/mysample_<nEvents>_<pulse_shift>_<pileup_shift>_<nSmpl>_<nFreq>_<amplitudeTruth>_<nPU>_<sigmaNoise>_<puFactor>_<wf_name>.root 

The form of the filename will be the same whether it uses the default values for those parameters or values that you specify.

This is pretty unwieldy to call by hand, so it is easier to use this script:

    python createAll.py 
    python createAll.py 0 -----> to have a dry run, only "cout" and no actual running
    
It is an interface to the code

    CreateData.C
    
and it will create a lot of files, one for each configuration:
    
    NTOYS = 1000
    NFREQS = [6.25, 12.5, 25]
    NSAMPLES = [10, 11, 12, 13, 14, 15, 20, 30, 40, 50, 60, 70, 80, 90]
    NPUS = [0, 20, 40, 140]
    AMPLITUDES = [1, 10, 100]



How to Fit data with multifit
====

First compile:

    g++ -o Example07.multifit.exe Example07.multifit.cc PulseChiSqSNNLS.cc -std=c++11 `root-config --cflags --glibs`
    mkdir outputfit
    
Then

    python fitAll.py
    python fitAll.py 0 -----> to have a dry run, only "cout" and no actual running
    
It is an interface to the code
    
    Example07.multifit.cc
    
    
Analyze and plot the results
====

see the analysis folder

    
    
    
    
    
    
    
    
    
    
    
