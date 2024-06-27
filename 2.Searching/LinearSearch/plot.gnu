set terminal pngcairo enhanced font "Arial,12" size 800,600
set output "LinearSearch.png"
set title "Linear Search"
set xrange [1:1200]
set yrange [1:1200]

set xlabel "Input size"
set ylabel "Op_count"

set style data linespoints

plot "output/bestcase.txt" title "Best case", "output/averagecase.txt" title "Average case", "output/worstcase.txt" title "Worst case"