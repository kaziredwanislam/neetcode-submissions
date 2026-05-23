class Index
{
    public int x;
    public int y;
}

class Result
{
    public boolean pacificOcean=false;
    public boolean atlanticOcean=false;
    
}

class Solution {
    boolean isValidIndex(int [][]heights,Index index)
    {
        if(index.x<0 || index.y<0)return false;
        if(index.x>=heights.length || index.y>=heights[0].length)return false;
        return true;
    }

    boolean adjPacific(int [][]heights,Index index)
    {
        if(index.x==0 || index.y==0)return true;
        return false;
    }
    boolean adjAtlantic(int [][]heights,Index index)
    {
        if(index.x==heights.length-1 || index.y==heights[0].length-1)return true;
        return false;
    }
    Result bfs(int [][]heights,boolean[][]visited,Index index)
    {
        boolean [][]traversed=new boolean[heights.length][heights[0].length];
        for(int i=0;i<traversed.length;i++)
        {
            for(int j=0;j<traversed[0].length;j++)
            {
                traversed[i][j]=false;
            }
        }

        Queue<Index>indexq=new LinkedList<>();
        indexq.add(index);
        Result result=new Result();
        while(!indexq.isEmpty())
        {
            Index curIndex=indexq.poll();
            if(adjPacific(heights,curIndex)&&adjAtlantic(heights,curIndex))
            {
                result.pacificOcean=true;
                result.atlanticOcean=true;
                //System.out.println(index.x+" "+index.y+" "+curIndex.x+" "+curIndex.y+" "+result.pacificOcean+" "+result.atlanticOcean);
                return result;
            }
            if(adjPacific(heights,curIndex))result.pacificOcean=true;
            if(adjAtlantic(heights,curIndex))result.atlanticOcean=true;
            Index index1=new Index();
            index1.x=curIndex.x+1;
            index1.y=curIndex.y;
            if(isValidIndex(heights,index1)&&heights[index1.x][index1.y]<=heights[curIndex.x][curIndex.y] && traversed[index1.x][index1.y]==false)
            {
                if(visited[index1.x][index1.y] || (adjPacific(heights,index1)&&adjAtlantic(heights,index1)))
                {
                    result.pacificOcean=true;
                    result.atlanticOcean=true;
                    return result;
                }
                if(adjPacific(heights,index1))
                {
                    result.pacificOcean=true;
                }
                if(adjAtlantic(heights,index1))
                {
                    result.atlanticOcean=true;
                }
                indexq.add(index1);
                traversed[index1.x][index1.y]=true;
            }

            Index index2=new Index();
            index2.x=curIndex.x-1;
            index2.y=curIndex.y;
            if(isValidIndex(heights,index2)&&heights[index2.x][index2.y]<=heights[curIndex.x][curIndex.y] && traversed[index2.x][index2.y]==false)
            {
                if(visited[index2.x][index2.y] || (adjPacific(heights,index2)&&adjAtlantic(heights,index2)))
                {
                    result.pacificOcean=true;
                    result.atlanticOcean=true;
                    return result;
                }
                if(adjPacific(heights,index2))
                {
                    result.pacificOcean=true;
                }
                if(adjAtlantic(heights,index2))
                {
                    result.atlanticOcean=true;
                }
                indexq.add(index2);
                traversed[index2.x][index2.y]=true;
            }

            Index index3=new Index();
            index3.x=curIndex.x;
            index3.y=curIndex.y+1;
            if(isValidIndex(heights,index3)&&heights[index3.x][index3.y]<=heights[curIndex.x][curIndex.y] && traversed[index3.x][index3.y]==false)
            {
                if(visited[index3.x][index3.y] || (adjPacific(heights,index3)&&adjAtlantic(heights,index3)))
                {
                    result.pacificOcean=true;
                    result.atlanticOcean=true;
                    return result;
                }
                if(adjPacific(heights,index3))
                {
                    result.pacificOcean=true;
                }
                if(adjAtlantic(heights,index3))
                {
                    result.atlanticOcean=true;
                }
                indexq.add(index3);
                traversed[index3.x][index3.y]=true;
            }

            Index index4=new Index();
            index4.x=curIndex.x;
            index4.y=curIndex.y-1;
            if(isValidIndex(heights,index4)&&heights[index4.x][index4.y]<=heights[curIndex.x][curIndex.y]&& traversed[index4.x][index4.y]==false)
            {
                if(visited[index4.x][index4.y] || (adjPacific(heights,index4)&&adjAtlantic(heights,index4)))
                {
                    result.pacificOcean=true;
                    result.atlanticOcean=true;
                    return result;
                }
                if(adjPacific(heights,index4))
                {
                    result.pacificOcean=true;
                }
                if(adjAtlantic(heights,index4))
                {
                    result.atlanticOcean=true;
                }
                indexq.add(index4);
                traversed[index4.x][index4.y]=true;
            }
        }
        return result;
    }

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int row=heights.length;
        int col=heights[0].length;
        boolean [][]visited=new boolean[row][col];
        for(int i=0;i<visited.length;i++)
        {
            for(int j=0;j<visited[0].length;j++)
            {
                visited[i][j]=false;
            }
        }

        for(int i=0;i<heights.length;i++)
        {
            for(int j=0;j<heights[0].length;j++)
            {
                Index index=new Index();
                index.x=i;
                index.y=j;
                Result res=bfs(heights,visited,index);
                //System.out.println(index.x+" "+index.y+" "+heights[0][4]+" "+ress.pacificOcean+" "+ress.atlanticOcean);
                if(res.pacificOcean && res.atlanticOcean)
                {
                    visited[i][j]=true;
                }
            }
        }

        List<List<Integer>>result=new ArrayList<>();
        for(int i=0;i<visited.length;i++)
        {
            for(int j=0;j<visited[0].length;j++)
            {
                if(visited[i][j]==true)
                {
                    List<Integer>res=new ArrayList<>();
                    res.add(i);
                    res.add(j);
                    result.add(res);
                }
            }
        }
        return result;
    }
}
