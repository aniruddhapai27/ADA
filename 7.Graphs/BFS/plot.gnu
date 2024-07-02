set title "BFS"
set xrange[*:*]
set yrange[*:*]

set xlabel "Input size"
set ylabel "Count"

set style data linespoints

plot "output/bestcase.txt" title "Best case",  "output/worstcase.txt" title "Worst case"