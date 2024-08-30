set terminal pngcairo enhance font "Arial,12" size 800,600
set output 'plot.png'

set title "KnapSack"
set xrange [*:*]
set yrange [*:*]

set xlabel "Input size"
set ylabel "Op_count"

set style data linespoints

plot "output/knap.txt" title "General case"