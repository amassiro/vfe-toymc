#!/bin/sh
#BSUB -J JOB.1
#BSUB -o output_file
#BSUB -e error_file
#BSUB -n 16
#BSUB -q ht-10g
#BSUB -cwd /home/sfraker/vfe-toymc
######## THIS IS A TEMPLATE FILE FOR TCP ENABLED MPI RUNS ON THE DISCOVERY CLUSTER ########
#### #BSUB -n has a value equal to the given value for the -np option ####
# prefix for next run is entered below
# file staging code is entered below

#### Enter your working directory below - this is the string returned from issuing the command #### "pwd"
#### IF you stage your files this is your run directory in the high speed scratch space mounted #### across all compute nodes
work=/home/sfraker/vfe-toymc
#####################################################
########DO NOT EDIT ANYTHING BELOW THIS LINE#########
#####################################################
cd $work
tempfile1=hostlistrun
tempfile2=hostlist-tcp
echo $LSB_MCPU_HOSTS > $tempfile1
declare -a hosts
read -a hosts < ${tempfile1}
for ((i=0; i<${#hosts[@]}; i += 2)) ;
do
HOST=${hosts[$i]}
CORE=${hosts[(($i+1))]}
echo $HOST:$CORE >> $tempfile2
done
#####################################################
########DO NOT EDIT ANYTHING ABOVE THIS LINE#########
#####################################################
###### The example below runs a GROMACS program mdrun_mpi.
###### Change only the -np option giving the number of MPI processes and the executable to use ###### with options to it
###### IN the example below this would be "10", "mdrun_mpi" and the options for the executable ###### " -s md.LD -v -noddcheck -maxh 0.1"
###### DO NOT CHANGE ANYTHING ELSE BELOW FOR mpirun OPTIONS
###### MAKE SURE THAT THE "#BSUB -n" is equal to the "-np" number below. IN this example it is ###### 10.
mpirun -np 16 -prot -TCP -lsf create_all_mpi4py.py -e 1
#/home/sfraker/mvfe-toymc/create_all_mpi4py.py
# any clean up tasks and file migration code is entered below
#####################################################
########DO NOT EDIT ANYTHING BELOW THIS LINE#########
#####################################################
rm $work/$tempfile1
rm $work/$tempfile2
#####################################################
########DO NOT EDIT ANYTHING ABOVE THIS LINE#########
#####################################################

