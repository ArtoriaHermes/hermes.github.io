<img width="973" height="692" alt="image" src="https://github.com/user-attachments/assets/85c888f4-9d6d-4e4f-8acf-51de5a469ca6" />
<img width="526" height="155" alt="image" src="https://github.com/user-attachments/assets/01050fe1-10e4-479a-b50b-53bbb39a0d19" />

English:
  Given m,n and k and a table *a* containing m*n elements (a[i][j] < 1000 for each 1 <= i <= m and 1 <= j <= n). Find the square sub-table with size k*k that has the largest sum
Restraints:
  + 50% tests: m, n, k < 100
  + 50% test: m, n, k > 100

  This is a basic 2D prefix sum problem. With the prefix sum matrix called pre[i][j], we have pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i][j]

  Then given a result variable called ans initially equal to -1e18 loop i from k to m, j from k to n, each loop we take pre[i][j]-pre[i-k][j]-pre[i][j-k]+pre[i-k][j-k], and ans will be equal to max(ans, pre[i][j]-pre[i-k][j]-pre[i][j-k]+pre[i-k][j-k])
