set terminal pngcairo enhanced font "Arial,12" size 800,600
set output "MergeSort.png"
set title "Merge Sort"
set xrange [*:*]
set yrange [*:*]

set xlabel "Input size"
set ylabel "Op_count"

set style data linespoints

plot "output/m_b.txt" title "Best case", "output/m_a.txt" title "Average case", "output/m_w.txt" title "Worst case"