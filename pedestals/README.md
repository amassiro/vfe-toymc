Pedestal studies
====

How a shift in pedestal reflect in energy shifts



Create data:

    g++ -o CreateData.exe  CreateData.C -std=c++11 `root-config --cflags --glibs`

    ./CreateData.exe     
    ./CreateData.exe    temporal_shift      number_of_events       NSAMPLES       NFREQ     nPU    signalAmplitude    sigmaNoise     puFactor  wf_name_string    pu_shift     noise-correlation    pedestal

e.g.

    ./CreateData.exe    0      1000     10    25   -->   10 samples sampled every 25ns

    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5    10

    
Plot the input:

    r99t plot/plotPulseInput.C\(\"input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_10.00.root\"\)
    r99t plot/plotPulseInput.C\(\"input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_1.00.root\"\)

    
Analyse data:

    g++ -o Example07.multifit.exe Example07.multifit.cc PulseChiSqSNNLS.cc -std=c++11 `root-config --cflags --glibs`
    
    
and fit:

                                                                                                                                                         NSAMPLES       NFREQ
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_10.00.root     output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_10.00.root       10            25


And plot:

    r99t plot/plotPulse.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_10.00.root\"\)
    r99t plot/plotPulse.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_10.00.root\",1\)
    r99t plot/plotPulse.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_10.00.root\",2\)

    r99t plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_10.00.root\"\)
     
    
    r99t plot/plotPulse.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_1.00.root\",2\)
    r99t plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_1.00.root\"\)

    r99t plot/plotPulse.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_1.00.root\",2\)

    r99t plot/plotPulse.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root\",2\)
    
     
Now systematically:

    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5      -1
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.1
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.09
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.08
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.07
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.06
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.05
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.04
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.03
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.02
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.01
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5       0.01
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5       0.02
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5       0.03
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5       0.04
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5       0.05
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5       0.06
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5       0.07
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5       0.08
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5       0.09
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5       0.1
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5       1


    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root     output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.10.root     output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.10.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.09.root     output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.09.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.08.root     output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.08.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.07.root     output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.07.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.06.root     output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.06.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.05.root     output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.05.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.04.root     output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.04.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.03.root     output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.03.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.02.root     output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.02.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.01.root     output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.01.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.01.root      output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.01.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.02.root      output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.02.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.03.root      output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.03.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.04.root      output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.04.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.05.root      output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.05.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.06.root      output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.06.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.07.root      output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.07.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.08.root      output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.08.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.09.root      output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.09.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.10.root      output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.10.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_1.00.root      output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_1.00.root       10            25

    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root\",-1.00\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.10.root\",-0.10\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.09.root\",-0.09\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.08.root\",-0.08\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.07.root\",-0.07\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.06.root\",-0.06\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.05.root\",-0.05\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.04.root\",-0.04\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.03.root\",-0.03\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.02.root\",-0.02\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.01.root\",-0.01\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root\",0.00\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.01.root\",0.01\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.02.root\",0.02\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.03.root\",0.03\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.04.root\",0.04\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.05.root\",0.05\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.06.root\",0.06\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.07.root\",0.07\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.08.root\",0.08\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.09.root\",0.09\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.10.root\",0.10\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_1.00.root\",1.00\)

    
    
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5      -1
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5      -0.1
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5      -0.09
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5      -0.08
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5      -0.07
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5      -0.06
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5      -0.05
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5      -0.04
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5      -0.03
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5      -0.02
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5      -0.01
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5       0
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5       0.01
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5       0.02
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5       0.03
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5       0.04
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5       0.05
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5       0.06
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5       0.07
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5       0.08
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5       0.09
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5       0.1
    ./CreateData.exe    0        11    10     25     0     100    0         0      CRRC43     0    0.5       1


    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-1.00.root     output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-1.00.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.10.root     output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.10.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.09.root     output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.09.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.08.root     output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.08.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.07.root     output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.07.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.06.root     output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.06.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.05.root     output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.05.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.04.root     output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.04.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.03.root     output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.03.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.02.root     output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.02.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.01.root     output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.01.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.00.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.01.root      output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.01.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.02.root      output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.02.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.03.root      output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.03.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.04.root      output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.04.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.05.root      output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.05.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.06.root      output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.06.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.07.root      output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.07.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.08.root      output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.08.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.09.root      output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.09.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.10.root      output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.10.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_1.00.root      output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_1.00.root       10            25

    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-1.00.root\",-1.00\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.10.root\",-0.10\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.09.root\",-0.09\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.08.root\",-0.08\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.07.root\",-0.07\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.06.root\",-0.06\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.05.root\",-0.05\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.04.root\",-0.04\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.03.root\",-0.03\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.02.root\",-0.02\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_-0.01.root\",-0.01\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.00.root\",0.00\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.01.root\",0.01\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.02.root\",0.02\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.03.root\",0.03\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.04.root\",0.04\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.05.root\",0.05\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.06.root\",0.06\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.07.root\",0.07\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.08.root\",0.08\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.09.root\",0.09\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_0.10.root\",0.10\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_100.00_0.00_0.000_0.00_CRRC43_1.00.root\",1.00\)

    
    
    
    
    
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5      -1
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5      -0.1
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5      -0.09
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5      -0.08
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5      -0.07
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5      -0.06
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5      -0.05
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5      -0.04
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5      -0.03
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5      -0.02
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5      -0.01
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5       0
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5       0.01
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5       0.02
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5       0.03
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5       0.04
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5       0.05
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5       0.06
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5       0.07
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5       0.08
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5       0.09
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5       0.1
    ./CreateData.exe    0        11    10     25     0     1    0         0      CRRC43     0    0.5       1


    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-1.00.root     output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-1.00.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.10.root     output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.10.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.09.root     output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.09.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.08.root     output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.08.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.07.root     output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.07.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.06.root     output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.06.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.05.root     output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.05.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.04.root     output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.04.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.03.root     output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.03.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.02.root     output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.02.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.01.root     output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.01.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.00.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.01.root      output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.01.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.02.root      output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.02.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.03.root      output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.03.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.04.root      output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.04.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.05.root      output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.05.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.06.root      output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.06.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.07.root      output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.07.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.08.root      output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.08.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.09.root      output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.09.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.10.root      output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.10.root       10            25
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_1.00.root      output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_1.00.root       10            25

    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-1.00.root\",-1.00\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.10.root\",-0.10\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.09.root\",-0.09\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.08.root\",-0.08\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.07.root\",-0.07\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.06.root\",-0.06\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.05.root\",-0.05\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.04.root\",-0.04\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.03.root\",-0.03\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.02.root\",-0.02\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_-0.01.root\",-0.01\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.00.root\",0.00\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.01.root\",0.01\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.02.root\",0.02\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.03.root\",0.03\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.04.root\",0.04\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.05.root\",0.05\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.06.root\",0.06\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.07.root\",0.07\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.08.root\",0.08\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.09.root\",0.09\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_0.10.root\",0.10\)
    r99t -q -b plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_1.00_0.00_0.000_0.00_CRRC43_1.00.root\",1.00\)

    
    
    
    
    
    r99t DrawBias.C
    
    
    
    