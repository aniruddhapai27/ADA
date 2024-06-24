set title "Linear Search"
set xrange [1:1200]
set yrange [1:1200]

set xlabel "Input size"
set ylabel "Op_count"

set style data linespoints

plot "bestcase.txt" title "Best case", "averagecase.txt" title "Average case", "worstcase.txt" title "Worst case"