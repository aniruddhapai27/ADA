set terminal pngcairo enhance font "Arial,12" size 800,600
set output 'plot.png'

set title "Quick Sort"
set xrange [*:*]
set yrange [*:*]

set xlabel "Input size"
set ylabel "Op_count"

set style data linespoints

plot "output/best.txt" title "Best case", "output/avg.txt" title "Average case", "output/worst.txt" title "Worst case"