set terminal pngcairo enhance font "Arial,12" size 800,600
set output 'plot.png'

set title "Warshall"
set xrange [*:*]
set yrange [*:*]

set xlabel "Input size"
set ylabel "Op_count"

set style data linespoints

plot "output/best.txt" title "Best case", "output/worst.txt" title "Worst case"