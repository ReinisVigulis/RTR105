#!/usr/bin/gnuplot --persist
#set terminal pngcairo transparent enhanced font "arial,10" fontscale 1.0 size 600, 400 
set terminal pngcairo enhanced font "arial,10" fontscale 1.0 size 600, 400 
set output 'atvasin+.png'

set grid

#plot [0:2*pi] sin(x*x)
#replot [0:2*pi] 2*x * cos(x*x) title "2x*cos(x*x)"
#replot "atvasin.dat" every ::1 using 1:2 with lines title "sin(x*x) (from file)",
#replot "atvasin.dat" every ::1 using 1:3 with lines title "sin'(x*x) (finite difference)"

plot [0:2*pi] sin(x*x), 2*x*cos(x*x), \
              "atvasin+.dat" every ::1 using 1:2 with lines title "sin(x*x) (from file)", \
              "atvasin+.dat" every ::1 using 1:3 with lines title "2*x*cos(x*x) (analitiski)", \
              "atvasin+.dat" every ::1 using 1:4 with lines title "2 * cos(x*x) - 4 * x * x * sin(x*x) (analitiski)", \
              "atvasin+.dat" every ::1 using 1:4 with lines title "2*x*cos(x*x) (skaitliski)", \
              "atvasin+.dat" every ::1 using 1:4 with lines title "2 * cos(x*x) - 4 * x * x * sin(x*x) (skaitliski)"
 

