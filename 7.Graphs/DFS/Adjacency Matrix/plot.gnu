set terminal pngcairo enhanced font "Arial,12" size 800,600
set output "DFS Adjacency matrix.png"
set title "DFS"
set xrange[*:*]
set yrange[*:*]

set xlabel "Input size"
set ylabel "Count"

set style data linespoints

plot "output/bestcase.txt" title "Best case",  "output/worstcase.txt" title "Worst case"