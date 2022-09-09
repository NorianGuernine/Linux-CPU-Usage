[![Total alerts](https://img.shields.io/lgtm/alerts/g/NorianGuernine/CPU_infos.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/NorianGuernine/CPU_infos/alerts/)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/NorianGuernine/CPU_infos.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/NorianGuernine/CPU_infos/context:cpp)

# What is Linux CPU Usage 

It is a tool that measures CPU usage.

# How to use it 

## Compilation

You have to use Cmake to compile.

Just run the following commands:

```
norian@norian-HP-Pavilion:~/Documents/github/CPU-Usage$ cmake .

norian@norian-HP-Pavilion:~/Documents/github/CPU-Usage$ make
```

A compiled file named cpu_utilzation appears.

## Use of the tool

Just run the compiled file with the command:

```
norian@norian-HP-Pavilion:~/Documents/github/CPU-Usage$ ./cpu_utilization
```


The first "cpu" line aggregates the numbers in all of the other "cpuN" lines.

![cpu-usage](https://github.com/NorianGuernine/Linux-CPU-Usage/blob/main/Pictures/cpu_utilization.png)
