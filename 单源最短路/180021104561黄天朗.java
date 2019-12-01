package lowPath;

public class Dijkstra {
    public static final int M = 10000; //权重无穷大（此处不用max_value是因为再往上加权重会溢出）
    
    public static void main(String[] args) {
        int[][] weight = {
                {0,4,M,2,M}, 
                {4,0,3,1,M}, 
                {M,3,0,1,3}, 
                {2,1,1,0,6},   
                {M,M,3,6,0} 
            };
			//权重图 weight[2][3]=1即3号点到4号点距离为1
			//为检阅方便，邻接矩阵为对称矩阵，即边的双向权重保持一致 

        int start = 0;//出发点设置为1号点
        
        int[] shortPath = dijkstra(weight, start);

        for (int i = 0; i < shortPath.length; i++)
            System.out.println("从" + (start+1) + "出发到" + (i+1) + "的最短距离为：" + shortPath[i]);
    }

    public static int[] dijkstra(int[][] weight, int start) {

        int n = weight.length; // 顶点个数
        int[] shortPath = new int[n]; //最短距离记录 
        String[] path = new String[n]; //最短路径记录
        for (int i = 0; i < n; i++)
            path[i] = new String(start + "-->" + i);
        int[] visited = new int[n]; // 访问记录

        //初始化
        shortPath[start] = 0;
        visited[start] = 1;
        
        //加入顶点 
        for (int count = 1; count < n; count++) {
            int k = -1;
            int dmin = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                if (visited[i] == 0 && weight[start][i] < dmin) {
                    dmin = weight[start][i];
                    k = i;
                }
            }

            //记录当前解 
            shortPath[k] = dmin;
            visited[k] = 1;

            //检查
            for (int i = 0; i < n; i++) {
                if (visited[i] == 0 && weight[start][k] + weight[k][i] < weight[start][i]) {
                    weight[start][i] = weight[start][k] + weight[k][i];
                    path[i] = path[k] + "-->" + i;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            System.out.println("从" + (start+1) + "出发到" + (i+1) + "的最短路径为：" + path[i]);
        }
        System.out.println("=====================================");
        return shortPath;
        //返回的数组shortPath记录了起点至各点的最短距离
    }
    
}