# About MRCT

MRCT is a program could find hub structure and coexpression module.

More information related the method, see [this link](https://github.com/zy26/MRHCA).
 
For the R codes which could reproduce the result of "MRHCA: A nonparametric statistics based method for hub and co-expression module identification in large gene co-expression network", see [this link](https://github.com/zy26/MRHCA-R).

# How  to clone the codes

```
git clone --recursive https://github.com/zy26/mrct.git
cd mrct/
```

Or, you can just click **Clone or download** under the repository name, then put the code files of ```libmrct``` to ```lib``` dir.

# How to compile and run the program?

## Linux

You may need g++ version >= 5.40.

```
g++ -std=c++14 -fopenmp -O3 lib/*.cc src/*.cc
```

```
./a.out -i testdata/E_coli_anaerobic.txt -o E_coli_anaerobic.id.txt -e E_coli_anaerobic.mr.txt -t 0.9
```

## Windows

Use Visual Studio project file ```mrct.vcxproj``` inside. You may need [modify the Platform Toolset](https://docs.microsoft.com/cpp/build/how-to-modify-the-target-framework-and-platform-toolset) to the version on your PC (You will need Visual Studio 2019 or higher to allow unsigned int for the OpenMP loop counter). 

The Command Arguments should be ```-i testdata/E_coli_anaerobic.txt -o E_coli_anaerobic.id.txt -e E_coli_anaerobic.mr.txt -t 0.9```, or you can use your file name instead.

Warning: Try to avoid **Debug** mode, it may be very slow.

# What does the output mean?

You will see the content of the first output file (`E_coli_anaerobic.id.txt`) as below somehow.

```
1	0	1639	979	b3385
1	0	1589	1232	b0421
1	0	1583	2167	b3649
1	0	1559	535	b0184
1	0	1549	3789	b4557
1	0	1547	2562	b3833
1	0	1532	2777	b0434
1	0	1528	960	b3560
1	0	1520	2837	b0637
1	0	1512	2115	b3704
1	0	1506	3861	b3999
1	0	1501	13	b3255
1	0	1496	1880	b4201
1	0	1481	698	b2610
1	0	1480	2425	b3838
1	0	1462	2112	b0183
1	0	1458	1049	b3997
1	0	1447	496	b3639
1	0	1433	2103	b0953
1	0	1426	1099	b4372
1	0	1417	1335	b3200
1	0	1414	2032	b3620
1	0	1409	2521	b2960
1	0	1406	566	b3640
1	0	1406	2113	b0610
1	0	1406	2133	b3985
1	0	1395	2489	b3035
1	0	1392	2520	b3651
1	0	1386	3769	b3611
1	0	1382	1340	b0179
1	0	1374	3770	b3614
1	0	1365	2066	b3783
1	0	1367	3727	b3499
1	0	1359	992	b3610
1	0	1344	1480	b1782
1	0	1342	2836	b0636
1	0	1340	2176	b3341
1	0	1330	1894	b1831
1	0	1325	1234	b2747
1	0	1315	2183	b3307
1	0	1315	4185	b2792
1	0	1314	2519	b2607
1	0	1314	823	b2748
1	0	1310	2126	b3984
1	0	1305	2134	b3983
1	0	1301	2181	b3342
1	0	1293	1694	b3982
1	0	1289	1305	b2828
1	0	1284	1551	b0923
1	0	1282	801	b0172
1	0	1273	1236	b2746
1	0	1265	197	b3734
1	0	1254	2336	b3641
1	0	1253	203	b3733
1	0	1245	4267	b4212
1	0	1232	204	b3735
1	0	1230	2784	b0471
1	0	1228	1336	b3201
1	0	1234	3746	b3552
1	0	1208	2539	b0170
1	0	1198	3592	b2953
1	0	1200	3104	b1447
1	0	1188	3498	b2643
1	0	1179	4245	b3199
1	0	1175	2204	b0176
1	0	1170	2146	b3318
1	0	1174	2292	b3981
1	0	1162	1828	b3821
1	0	1164	2030	b3619
1	0	1160	1762	b2320
1	0	1171	3606	b2986
1	0	1136	2535	b2745
1	0	1124	846	b3340
1	0	1139	1048	b3804
1	0	1134	2427	b4483
1	0	1119	2849	b0699
1	0	1116	2122	b3643
1	0	1121	2972	b1034
1	0	1101	4243	b3195
1	0	1087	3788	b3705
1	0	1078	1854	b4226
1	0	1077	3285	b1978
1	0	1086	2168	b2830
1	0	1070	3603	b2983
1	0	1068	2932	b0898
1	0	1052	969	b2029
1	0	1077	3231	b1803
1	0	1051	3736	b3527
1	0	1025	4242	b3194
1	0	1016	363	b0624
1	0	1030	1900	b0331
1	0	979	3328	b2122
1	0	977	4175	b2647
1	0	969	3417	b2358
1	139	0	2013	b3700
1	0	972	3416	b2357
1	0	977	2742	b0285
1	0	975	1477	b1175
1	0	937	1158	b2490
1	0	942	277	b1987
1	0	924	4176	b2650
1	0	951	1534	b2113
1	0	932	2528	b1265
1	0	896	2875	b0718
1	0	933	2034	b3842
1	0	876	2060	b3901
1	0	881	2811	b0521
1	0	853	3421	b2362
1	372	0	2233	b1012
1	0	901	1252	b3526
1	0	848	2640	b2047
1	0	840	809	b3897
1	0	836	3536	b2770
1	0	844	4094	b1585
1	0	885	1825	b2648
1	0	865	1253	b1827
1	364	0	3073	b1360
1	131	0	2612	b1914
1	0	834	3032	b1251
1	0	813	340	b2933
1	293	0	2302	b2913
1	0	816	2639	b2050
1	0	849	3835	b3878
1	0	819	1757	b3403
1	0	840	3196	b1724
1	183	0	3244	b1832
1	324	0	2747	b0291
1	135	0	3007	b1179
1	289	0	1570	b0750
1	0	801	2865	b0719
1	308	0	1295	b0075
1	0	805	3190	b1698
1	0	791	2727	b0267
1	0	799	1801	b4105
1	373	0	3535	b2769
1	291	0	1443	b3008
1	0	792	661	b1701
1	357	0	2746	b0290
1	315	0	3418	b2359
1	0	786	3078	b1407
1	0	779	4171	b2547
1	0	781	3629	b3080
1	221	0	2455	b2103
1	288	0	127	b3172
1	0	779	3415	b2356
1	0	781	2307	b1975
1	0	781	3913	b4183
1	0	773	2952	b0941
1	0	784	2467	b0002
1	374	0	1248	b3137
1	371	0	3912	b4182
1	253	0	121	b2818
1	247	0	126	b0273
1	318	0	3385	b2294
1	0	768	2859	b0682
1	368	0	122	b3959
1	0	768	2647	b2061
1	231	0	1194	b0077
1	201	0	123	b3958
1	367	0	1730	b1392
1	211	0	2463	b2104
1	214	0	1290	b0074
1	0	761	153	b0754
1	304	0	1727	b1389
1	0	738	795	b4474
1	346	0	3456	b2506
1	228	0	167	b0860
1	218	0	1193	b0078
1	325	0	7	b1338
1	177	0	1957	b1302
1	0	738	359	b2048
1	254	0	2085	b1066
1	209	0	158	b0112
1	0	736	4017	b4572
1	233	0	1293	b0071
1	207	0	2459	b3990
1	223	0	2526	b1263
1	236	0	1639	b3661
1	219	0	1444	b3829
1	237	0	1292	b0072
1	233	0	3626	b3074
1	210	0	889	b1761
1	239	0	124	b3359
1	309	0	2642	b2044
1	212	0	376	b1040
1	199	0	1441	b4013
1	202	0	1291	b0073
1	206	0	378	b1038
1	224	0	129	b4254
1	220	0	3582	b2930
1	218	0	2523	b1260
1	141	0	2939	b0906
1	136	0	665	b2097
1	131	0	2420	b1519
```

That means: We find 194 hubs. 
The second column is the cluster bound of the cluster. 
The third column is a upper bound of the cluster.
The forth column is the index of the original rows in the matrix of the input file. 
The last column is the row names of the forth column. 

We can use the [R package](https://github.com/zy26/MRHCA-R) fix the thrid column later.

We have another output file, the first column in it is the same as the forth column of the file below.
Other columns are the EM values for that row.
