set terminal pngcairo enhance font "Arial,12" size 800,600
set output 'plot.png'

set title "Topological Sorting"
set xrange [*:*]
set yrange [*:*]

set xlabel "Input size"
set ylabel "Op_count"

set style data linespoints

plot "output/topo.txt" title "General case"