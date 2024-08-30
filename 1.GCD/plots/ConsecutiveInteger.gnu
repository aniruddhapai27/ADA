set terminal pngcairo enhance font "Arial,12" size 800,600
set output 'ConsecutiveInteger.png'

set title "Consecutive Integer"
set xrange [*:*]
set yrange [*:*]

set xlabel "Input size"
set ylabel "Op_count"

set style data linespoints

plot "../output/consecBest.txt" title "Best case",  "../output/consecWorst.txt" title "Worst case"