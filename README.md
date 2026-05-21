# SD-SL3
## TODO
setelah ngertiin solusi-solusi ini, coba implementasi soal 1 pake bfs/dfs ama soal 5 pakai bfs/dfs juga
> [!TIP]
> DSU yang dipakai di kedua soal itu digunakan untuk menghitung disjointed graph (graph yang terpisah-pisah). BFS/DFS juga bisa digunakan untuk menghitung jumlah komponen terpisah dalam graph. Jadi, kamu bisa menggunakan BFS/DFS untuk menjelajahi graph dan menghitung jumlah komponen terpisah, sama seperti yang dilakukan oleh DSU. Coba implementasikan kedua soal tersebut menggunakan BFS/DFS untuk melihat bagaimana cara kerjanya!

> [!NOTE]
> Cara menghitung jumlah komponen terpisah menggunakan dsu itu dengan awal mengasumsi setiap node itu adalah graph terpisah, lalu menghitung edge list yang menghubungkan node-node tersebut, dan setiap kali menemukan edge yang menghubungkan dua node, kita akan menggabungkan kedua node tersebut menjadi satu komponen. Setelah semua edge diproses, jumlah komponen terpisah dapat dihitung dengan menghitung jumlah root unik dalam struktur DSU.

> [!NOTE]
> Untuk BFS/DFS, kita mulai menghitung dari 0 (awal). Setiap kali kita menemukan node yang belum dikunjungi, kita akan melakukan BFS/DFS untuk menjelajahi semua node yang terhubung dengan node tersebut, dan setiap kali kita menyelesaikan BFS/DFS, kita akan menambah jumlah komponen terpisah. Setelah semua node diproses, jumlah komponen terpisah dapat dihitung dengan menghitung berapa kali kita melakukan BFS/DFS.