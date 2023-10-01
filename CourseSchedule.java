class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {

    List<List<Integer>> graph = new ArrayList<>(numCourses);

    for(int i=0; i<numCourses; i++){

        graph.add(new ArrayList<>());
    } 

    // cal indegree

    int indegree [] = new int[numCourses];

    for(int [] prerequisite : prerequisites){

        int courseA = prerequisite[0];
        int courseB = prerequisite[1];

        graph.get(courseB).add(courseA);
        indegree[courseA]++;

    }

    Queue<Integer> q = new LinkedList<>();

    for(int i=0; i<numCourses; i++){
        if(indegree[i] == 0){
            q.add(i);
        }
    }

    //bfs

    int courseTaken = 0;

    while(!q.isEmpty()){

        int course = q.remove();
        courseTaken++;


        // decrease indegree of neighbour
        for(int neighbour : graph.get(course)){

            indegree[neighbour]--;

            if(indegree[neighbour] == 0){
                q.add(neighbour);
            }

        }


    }


        return courseTaken == numCourses;


        
    }
}
