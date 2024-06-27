set terminal pngcairo enhanced font "Arial,12" size 800,600
set output 'plot.png'
set title "Binary Search"
set xrange[1 : 1200]
set yrange[1 : 12]

set xlabel "Input size"
set ylabel "Count"

set style data linespoints

plot "output/bestcase.txt" title "Best case", "output/averagecase.txt" title "Average Case", "output/worstcase.txt" title "Worst case"