import glob
import os
import sys

def main(files, overwrite=True, dryrun=0):
    for f in files:
        i = f
        o = f.replace('input', 'outputfit').replace('mysample', 'output')
        if not overwrite and os.path.exists(o):
          #print "skipping %s --> %s because %s already exists." %(i, o, o)
          continue  # not recreating+overwriting existing files
        params = f.split('_')
        NSAMPLES, NFREQ = params[4 : 6]
        toExec = 'bin/Example07.multifit %s %s %s %s' % (i, o, NSAMPLES, NFREQ)
        print toExec
        if (dryrun == 0) :
            os.system(toExec)

if __name__ == '__main__':

    args = []
    # for loop that converts arguments with a '*' to the corresponding files
    for arg in sys.argv[1:]:
        args += glob.glob(arg)
    if not args:
        args = glob.glob('input/mysample_*')
    main(args)
