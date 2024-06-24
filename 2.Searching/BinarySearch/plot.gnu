set title "Binary Search"
set xrange[1 : 1200]
set yrange[1 : 12]

set xlabel "Input size"
set ylabel "Count"

set style data linespoints

plot "bestcase.txt" title "Best case", "averagecase.txt" title "Average Case", "worstcase.txt" title "Worst case"