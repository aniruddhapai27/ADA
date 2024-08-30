set terminal pngcairo enhance font "Arial,12" size 800,600
set output 'ModifiedEuclid.png'

set title "Modified Euclid"
set xrange [*:*]
set yrange [*:*]

set xlabel "Input size"
set ylabel "Op_count"

set style data linespoints

plot "../output/modifiedBest.txt" title "Best case",  "../output/modifiedWorst.txt" title "Worst case"