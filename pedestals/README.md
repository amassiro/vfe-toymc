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

    ./CreateData.exe    0        11    20     25     0     10    0         0      CRRC43     0    0.5       0
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_20_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root    output/output_11_0.000_0.000_20_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root       20            25

    r99t plot/plotPulse.C\(\"output/output_11_0.000_0.000_20_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root\",2\)
    r99t plot/plot.C\(\"output/output_11_0.000_0.000_20_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root\"\)

    
    ./CreateData.exe    0        11    20     12.5     0     10    0         0      CRRC43     0    0.5       0
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_20_12.50_10.00_0.00_0.000_0.00_CRRC43_0.00.root    output/output_11_0.000_0.000_20_12.50_10.00_0.00_0.000_0.00_CRRC43_0.00.root       20            12.5

    r99t plot/plotPulse.C\(\"output/output_11_0.000_0.000_20_12.50_10.00_0.00_0.000_0.00_CRRC43_0.00.root\",2\)
    r99t plot/plot.C\(\"output/output_11_0.000_0.000_20_12.50_10.00_0.00_0.000_0.00_CRRC43_0.00.root\"\)

    
    
    ./CreateData.exe    0        11    40     6.25     0     10    0         0      CRRC43     0    0.5       0
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_40_6.25_10.00_0.00_0.000_0.00_CRRC43_0.00.root    output/output_11_0.000_0.000_40_6.25_10.00_0.00_0.000_0.00_CRRC43_0.00.root       40            6.25

    r99t plot/plotPulse.C\(\"output/output_11_0.000_0.000_40_6.25_10.00_0.00_0.000_0.00_CRRC43_0.00.root\",2\)
    r99t plot/plot.C\(\"output/output_11_0.000_0.000_40_6.25_10.00_0.00_0.000_0.00_CRRC43_0.00.root\"\)

    
    
    ./CreateData.exe    0        11    40     6.25     100     10    0         10      CRRC43     0    0.5       0
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_40_6.25_10.00_100.00_0.000_10.00_CRRC43_0.00.root    output/output_11_0.000_0.000_40_6.25_10.00_100.00_0.000_10.00_CRRC43_0.00.root      40            6.25

    r99t plot/plotPulse.C\(\"output/output_11_0.000_0.000_40_6.25_10.00_100.00_0.000_10.00_CRRC43_0.00.root\",2\)
    r99t plot/plot.C\(\"output/output_11_0.000_0.000_40_6.25_10.00_100.00_0.000_10.00_CRRC43_0.00.root\"\)

    
    
    ./CreateData.exe    0        200    40     6.25     100     10    0         10      CRRC43     0    0.5       0
    ./Example07.multifit.exe    input/mysample_200_0.000_0.000_40_6.25_10.00_100.00_0.000_10.00_CRRC43_0.00.root    output/output_200_0.000_0.000_40_6.25_10.00_100.00_0.000_10.00_CRRC43_0.00.root      40            6.25

    r99t plot/plotPulse.C\(\"output/output_200_0.000_0.000_40_6.25_10.00_100.00_0.000_10.00_CRRC43_0.00.root\",2\)
    r99t plot/plot.C\(\"output/output_200_0.000_0.000_40_6.25_10.00_100.00_0.000_10.00_CRRC43_0.00.root\"\)
    
    
    ./CreateData.exe    0        200    10     25.00     100     10    0         10      CRRC43     0    0.5       0
    ./Example07.multifit.exe    input/mysample_200_0.000_0.000_10_25.00_10.00_100.00_0.000_10.00_CRRC43_0.00.root    output/output_200_0.000_0.000_10_25.00_10.00_100.00_0.000_10.00_CRRC43_0.00.root      10            25.00

    r99t plot/plotPulse.C\(\"output/output_200_0.000_0.000_10_25.00_10.00_100.00_0.000_10.00_CRRC43_0.00.root\",2\)
    r99t plot/plotPulse.C\(\"output/output_200_0.000_0.000_10_25.00_10.00_100.00_0.000_10.00_CRRC43_0.00.root\",3\)
    r99t plot/plotPulse.C\(\"output/output_200_0.000_0.000_10_25.00_10.00_100.00_0.000_10.00_CRRC43_0.00.root\",4\)
    r99t plot/plot.C\(\"output/output_200_0.000_0.000_10_25.00_10.00_100.00_0.000_10.00_CRRC43_0.00.root\"\)
    
    
    
    ./CreateData.exe    0        100    10     25.00     100     10    0         10      CRRC43     0    0.5       0
    ./Example07.multifit.exe    input/mysample_100_0.000_0.000_10_25.00_10.00_100.00_0.000_10.00_CRRC43_0.00.root    output/output_100_0.000_0.000_10_25.00_10.00_100.00_0.000_10.00_CRRC43_0.00.root      10            25.00

    r99t plot/plotPulse.C\(\"output/output_100_0.000_0.000_10_25.00_10.00_100.00_0.000_10.00_CRRC43_0.00.root\",2\)
    r99t plot/plotPulse.C\(\"output/output_100_0.000_0.000_10_25.00_10.00_100.00_0.000_10.00_CRRC43_0.00.root\",3\)
    r99t plot/plotPulse.C\(\"output/output_100_0.000_0.000_10_25.00_10.00_100.00_0.000_10.00_CRRC43_0.00.root\",4\)
    r99t plot/plot.C\(\"output/output_100_0.000_0.000_10_25.00_10.00_100.00_0.000_10.00_CRRC43_0.00.root\"\)
    
    
    
    
    ./CreateData.exe    0        11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe    1        11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe    2        11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe    3        11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe    4        11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe    5        11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -1        11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -2        11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -3        11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -4        11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -5        11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -6        11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -7        11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -8        11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -9        11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -10       11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -11       11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -12       11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -13       11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -14       11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -15       11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -16       11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -17       11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -18       11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -19       11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe   -20       11    10     25     0     10    0         0      CRRC43     0    0.5       0

    


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


    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5      -1
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.1
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.09
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.08
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.07
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.06
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.05
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.04
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.03
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.02
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5      -0.01
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5       0
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5       0.01
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5       0.02
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5       0.03
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5       0.04
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5       0.05
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5       0.06
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5       0.07
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5       0.08
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5       0.09
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5       0.1
    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5       1


    
    
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

    
    
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root       10            25        13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.10.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.10.root       10            25        13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.09.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.09.root       10            25        13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.08.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.08.root       10            25        13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.07.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.07.root       10            25        13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.06.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.06.root       10            25        13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.05.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.05.root       10            25        13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.04.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.04.root       10            25        13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.03.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.03.root       10            25        13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.02.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.02.root       10            25        13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.01.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.01.root       10            25        13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root       10            25         13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.01.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.01.root       10            25         13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.02.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.02.root       10            25         13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.03.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.03.root       10            25         13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.04.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.04.root       10            25         13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.05.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.05.root       10            25         13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.06.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.06.root       10            25         13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.07.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.07.root       10            25         13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.08.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.08.root       10            25         13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.09.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.09.root       10            25         13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.10.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.10.root       10            25         13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_1.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_1.00.root       10            25         13

    output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root
    
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root\",-1.00\)

    
    
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


    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root\",-1.00\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.10.root\",-0.10\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.09.root\",-0.09\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.08.root\",-0.08\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.07.root\",-0.07\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.06.root\",-0.06\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.05.root\",-0.05\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.04.root\",-0.04\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.03.root\",-0.03\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.02.root\",-0.02\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-0.01.root\",-0.01\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root\",0.00\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.01.root\",0.01\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.02.root\",0.02\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.03.root\",0.03\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.04.root\",0.04\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.05.root\",0.05\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.06.root\",0.06\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.07.root\",0.07\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.08.root\",0.08\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.09.root\",0.09\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.10.root\",0.10\)
    r99t -q -b plot/plot.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_1.00.root\",1.00\)

    
    r99t  plot/plotPulseInputMany.C
    
    r99t  plot/plotPulseInput.C\(\"input/mysample_11_5.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root\"\)
    r99t  plot/plotPulseInput.C\(\"input/mysample_11_4.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root\"\)
    r99t  plot/plotPulseInput.C\(\"input/mysample_11_3.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root\"\)
    r99t  plot/plotPulseInput.C\(\"input/mysample_11_2.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root\"\)
    r99t  plot/plotPulseInput.C\(\"input/mysample_11_1.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root\"\)
    r99t  plot/plotPulseInput.C\(\"input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root\"\)
    
    ./Example07.multifit.exe    input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root    output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root       10            25

    r99t plot/plotPulse.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root\",2\)
    r99t plot/plot.C\(\"output/output_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root\"\)

    ./CreateData.exe  -13        11    10     25     0     10    0         0      CRRC43     0    0.5       0

    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root       10            25
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root       10            25    13
        
    r99t plot/plotPulse.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root\",2\)
    r99t plot/plotPulse.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root\",2\)

        
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.root       10            25         13
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_1.root       10            25         14
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_2.root       10            25         15
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_3.root       10            25         16
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-1.root      10            25         12
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-2.root      10            25         11
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-3.root      10            25         10

    
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.1.root       10            25         13.1
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.2.root       10            25         13.2
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.3.root       10            25         13.3
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.4.root       10            25         13.4
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.5.root       10            25         13.5
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.6.root       10            25         13.6
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.7.root       10            25         13.7
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.8.root       10            25         13.8
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.9.root       10            25         13.9

    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.9.root       10            25         12.1
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.8.root       10            25         12.2
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.7.root       10            25         12.3
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.6.root       10            25         12.4
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.5.root       10            25         12.5
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.4.root       10            25         12.6
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.3.root       10            25         12.7
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.2.root       10            25         12.8
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root      output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.1.root       10            25         12.9
    
    r99t plot/TimeShift.C
    r99t plot/TimeShift.C\(1\)
        
    r99t plot/plotPulse.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.root\",2\)
    r99t plot/plotPulse.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.1.root\",2\)
    r99t plot/plotPulse.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.6.root\",2\)
    r99t plot/plotPulse.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.7.root\",2\)
    r99t plot/plotPulse.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.8.root\",2\)
    r99t plot/plotPulse.C\(\"output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.9.root\",2\)

    
    
    
    
    
    
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_0.0.root       10            25        13      0.0
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_0.1.root       10            25        13      -0.1
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_0.6.root       10            25        13      -0.6
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_0.7.root       10            25        13      -0.7
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_0.8.root       10            25        13      -0.8
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_0.9.root       10            25        13      -0.9
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_1.0.root       10            25        13      -1.0
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_1.1.root       10            25        13      -1.1
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_1.2.root       10            25        13      -1.2
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_1.3.root       10            25        13      -1.3
    ./Example07.multifit.exe    input/mysample_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00.root     output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_1.4.root       10            25        13      -1.4

    r99t plot/PedestalShift.C
    
    

    
        
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
    
    
    
    