package main

import (
	"fmt"
)

func matrixChain(p []int, n int) ([][]int, [][]int) {
	m, s := make([][]int, n), make([][]int, n)
    for i := 0; i < n; i++ {
        m[i], s[i] = make([]int, n),  make([]int, n)
    }
	
	for i := 0; i < n; i++ {
		m[i][i] = 0
	}

	for r := 2; r <= n; r++ {
		for i := 1; i < n - r + 1; i++ {
			j := i + r -1
			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j]
			s[i][j] = i
			for k := i+1; k < j; k++ {
				t := m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]
				if t < m[i][j] {
					m[i][j] = t
					s[i][j] = k
				}
			}
		}
	}

	return m, s
}

func main() {
	var n int // 矩阵个数

	fmt.Println("请输入矩阵个数：")
	fmt.Scanln(&n)

	var p []int = make([]int, n*2)// 矩阵行列数组
	
	for i := 0; i < n*2; i += 2 {
		fmt.Println("请输入矩阵行列数：")
		fmt.Scanln(&p[i], &p[i+1])
	}

	m, _ := matrixChain(p, n)

	fmt.Println(m)
}
