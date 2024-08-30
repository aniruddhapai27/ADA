set terminal pngcairo enhance font "Arial,12" size 800,600
set output 'Euclid.png'

set title "Euclid"
set xrange [*:*]
set yrange [*:*]

set xlabel "Input size"
set ylabel "Op_count"

set style data linespoints

plot "../output/euclidBest.txt" title "Best case",  "../output/euclidWorst.txt" title "Worst case"