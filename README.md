# About MRCT

MRCT is a program could find hub structure and coexpression module.

More information related the method, see [this link](https://github.com/zy26/MRHCA).
 
For the R codes which could reproduce the result of "MRHCA: A nonparametric statistics based method for hub and co-expression module identification in large gene co-expression network", see [this link](https://github.com/zy26/MRHCA-R).

# How  to clone the codes

```
git clone --recursive https://github.com/zy26/mrct.git
```

Or, you can just click **Clone or download** under the repository name, then put the code files of ```libmrct``` to ```lib``` dir.

# How to compile and run the program?

## Linux

```
g++ -std=c++11 -fopenmp -O3 lib/*.cc src/*.cc
```

```
./a.out testdata/E_coli_anaerobic.txt E_coli_anaerobic.output.txt 0.0025
```

## Windows

Use Visual Studio project file ```mrct.vcxproj``` inside.

The Command Arguments should be ```testdata/E_coli_anaerobic.txt E_coli_anaerobic.output.txt 0.0025```, or you can use your file name instead.

Warning: Try to avoid **Debug** mode, it may be very slow.

# What does the output mean?

You will see the content of output file as below somehow.

```
1 750 2483
1 750 2477
1 750 2470
1 750 2467
1 750 2447
1 750 2398
1 750 2397
1 750 2394
1 750 2376
1 750 2368
```

That means: We find 10 hubs. The cluster bound is 750. The last column is the index of the original rows in the matrix of the input file. 
