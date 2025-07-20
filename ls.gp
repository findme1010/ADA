set title 'Linear Search'
set xrange[0:110]
set yrange[0:110]
set xlabel 'Input Size'
set ylabel 'Operation Count
set xtics (0,10,20,30,40,50,60,70,80,90,100,110)
set ytics (0,10,20,30,40,50,60,70,80,90,100,110)
set style data linespoints
plot 'analysis.txt' using 1:2 title 'Best case','analysis.txt' using 1:3 title 'Avg case','analysis.txt' using 1:4 title 'Worst case'