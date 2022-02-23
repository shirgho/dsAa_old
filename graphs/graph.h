#include <assert.h>
#include <vector>
#include <iterator>
#include <memory.h>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

template<typename T>
class GraphVertex
{
    public:
        GraphVertex(T node) : m_node(node)
        {

        }

        T GetNode()
        {
            return m_node;
        }

    private:
        T m_node;
};

class EdgeInfo
{
    public:
        EdgeInfo() : m_v1Index(0), m_v2Index(0), m_weight(0){}

    bool operator<(const EdgeInfo &e2)
    {
        return (m_weight < e2.m_weight);
    }


    bool operator==(const EdgeInfo &e2)
    {
        return (m_v2Index == e2.m_weight);
    }

    int m_v1Index, m_v2Index;
    int m_weight;
};

template<typename T>
class Graph
{
    public:
        Graph(int numVerts) : m_maxVerts(numVerts), m_adjMatrix(NULL)
        {
            // ALLOCATE NECESSARY MEMORY
            assert(numVerts > 0);

            m_vertices.reserve(m_maxVerts);

            m_adjMatrix = new char*[m_maxVerts];
            assert(m_adjMatrix != NULL);

            for(int i = 0; i < m_maxVerts; i++){
                m_adjMatrix[i] = new char[m_maxVerts];
                assert(m_adjMatrix[i] != NULL);

                memset(m_adjMatrix[i], 0, m_maxVerts);
            }

            m_vertVisits = new char[m_maxVerts];
            assert(m_vertVisits != NULL);

            memset(m_vertVisits, 0, m_maxVerts);
        }

        ~Graph()
        {
            // DELETE ALLOCATED MEMORY
            if(m_adjMatrix != NULL){
                for(int i = 0; i < m_maxVerts; i++){
                    if(m_adjMatrix[i] != NULL){
                        delete[] m_adjMatrix[i];
                        m_adjMatrix[i] = NULL;
                    }
                }

                delete[] m_adjMatrix;
                m_adjMatrix = NULL;
            }

            if(m_vertVisits != NULL){
                delete[] m_vertVisits;
                m_vertVisits = NULL;
            }
            
        }

        bool push(T node)
        {
            if((int)m_vertices.size() >= m_maxVerts)
            return false;

            m_vertices.push_back(GraphVertex<T>(node));
            return true;
        }

        void attachEdge(int index1, int index2)
        {
            assert(m_adjMatrix != NULL);

            m_adjMatrix[index1][index2] = 1;
            m_adjMatrix[index2][index1] = 1;
        }
        
        void attachDirectedEdge(int index1, int index2)
        {
            assert(m_adjMatrix != NULL);

            m_adjMatrix[index1][index2] = 1;
        }

        int getNextUnvisitedVertex(int index)
        {
            assert(m_adjMatrix != NULL);
            assert(m_vertVisits != NULL);

            for(int i = 0; i < (int)m_vertices.size(); i++){
                if(m_adjMatrix[index][i] == 1 && m_vertVisits[i] == 0){
                    return i;
                }
            }

            return -1;
        }

        bool DepthFirstSearch(int startIndex, int endIndex)
        {
            assert(m_adjMatrix != NULL);
            assert(m_vertVisits != NULL);

            m_vertVisits[startIndex] = 1;

            // FOR OUTPUT PURPOSES OF THE DEMOS
            cout << m_vertices[startIndex].GetNode();

            stack<int> searchStack;
            int vert = 0;

            searchStack.push(startIndex);

            while(searchStack.empty() != true){
                vert = getNextUnvisitedVertex(searchStack.top());

                if(vert == -1){
                    searchStack.pop();
                } else {
                    m_vertVisits[vert] = 1;
                    cout << m_vertices[vert].GetNode();

                    searchStack.push(vert);
                }

                if(vert == endIndex){
                    memset(m_vertVisits, 0, m_maxVerts);
                    return true;
                }
            }

            memset(m_vertVisits, 0, m_maxVerts);
            return false;
        }

        bool BreadthFirstSearch(int startIndex, int endIndex)
        {
            assert(m_adjMatrix != NULL);
            assert(m_vertVisits != NULL);

            m_vertVisits[startIndex] = 1;

            cout << m_vertices[startIndex].GetNode();

            queue<int> searchQueue;
            int vert1 = 0, vert2 = 0;

            searchQueue.push(startIndex);

            while(searchQueue.empty() != true){
                vert1 = searchQueue.front();
                searchQueue.pop();

                if(vert1 == endIndex){
                    memset(m_vertVisits, 0, m_maxVerts);
                    return true;
                }

                while((vert2 = getNextUnvisitedVertex(vert1)) != -1){
                    m_vertVisits[vert2] = 1;

                    cout << m_vertices[vert2].GetNode();
                    searchQueue.push(vert2);
                }
            }

            memset(m_vertVisits, 0, m_maxVerts);

            return false;

        }

        void DisplayMST()
        {
            assert(m_adjMatrix != NULL);
            assert(m_adjMatrix != NULL);

            int startIndex = 0;

            m_vertVisits[startIndex] = 1;

            stack<int> searchStack;
            int vert = 0, currentVert = 0;

            searchStack.push(startIndex);

            while(searchStack.empty() != true){
                currentVert = searchStack.top();
                vert = getNextUnvisitedVertex(currentVert);

                if(vert == -1){
                    searchStack.pop();
                } else {
                    m_vertVisits[vert] = 1;
                    searchStack.push(vert);

                    cout << m_vertices[currentVert].GetNode()
                         << ":" << m_vertices[vert].GetNode()
                         << " ";
                }
            }

            memset(m_vertVisits, 0, m_maxVerts);
        }

        void DisplayMSTShortest(string &output)
        {
            assert(m_adjMatrix != NULL);
            assert(m_adjMatrix != NULL);

            int currentVert = 0, totalChecked = 0;
            int size = (int)m_vertices.size();

            vector<EdgeInfo> vList;

            while(totalChecked < size - 1){

                m_vertVisits[currentVert] = 1;
                totalChecked++;

                for(int i = 0; i < size; i++){
                    if(i == currentVert || m_vertVisits[i] == 1 ||
                        m_adjMatrix[currentVert][i] == 0)
                        continue;

                    EdgeInfo edge;
                    edge.m_v1Index = currentVert;
                    edge.m_v2Index = i;
                    edge.m_weight = m_adjMatrix[currentVert][i];

                    vector<EdgeInfo>::iterator it = find(vList.begin(), 
                                                         vList.end(),
                                                         edge);

                    if(it == vList.end()){
                        vList.push_back(edge);
                    } else {
                        if(edge.m_weight <= (*it).m_weight){
                            (*it).m_v1Index = edge.m_v1Index;
                            (*it).m_v2Index = edge.m_v1Index;
                            (*it).m_weight = edge.m_weight;
                        }
                    }
                }

                if(vList.empty() == true){
                    output = "Error: Graph is not connected.";
                    return;
                }

                // Orders from greatest to least.
                // Since we have to sort anyhow lets put the min at the
                // end so pop_back() is fast
                sort(vList.rbegin(), vList.rend());

                int endIndex = (int)vList.size() - 1;
                int v1 = vList[endIndex].m_v1Index;
                currentVert = vList[endIndex].m_v2Index;

                //For demo output
                output += m_vertices[v1].GetNode();
                output += ";";
                output += m_vertices[currentVert].GetNode();
                output += " ";

                //remove minimum, which was placed at the back
                vList.pop_back();
            }
            memset(m_vertVisits, 0, m_maxVerts);
        }

        // if list used instead of matrix, could be faster
        // have to only check if the list for that row has any elements
        int GetVertNoSuccessor(char **adjMat, int size)
        {
            bool edgeFound = false;

            for(int row = 0; row < size; row++){
                edgeFound = false;
                for(int col = 0; col < size; col++){
                    if(adjMat[row][col] != 0){
                        edgeFound = true;
                        break;
                    }                
                }
                if(edgeFound == false)
                    return row;
            }
            return -1;
        }

        bool topologicalSort(list<T> &output)
        {
            bool hasCycles = false;

            //Create copies of data so original not destroyed
            vector<GraphVertex<T>> tempVerts(m_vertices);
            
            int tempSize = (int)tempVerts.size();
            
            char **tempAdjMat = new char*[m_maxVerts];
            assert(tempAdjMat != NULL);

            for(int i = 0; i < m_maxVerts; i++){
                tempAdjMat[i] = new char[m_maxVerts];
                assert(tempAdjMat[i] != NULL);

                memcpy(tempAdjMat[i], m_adjMatrix[i], m_maxVerts);
            }

            //Perform Topological Sort
            while(tempSize > 0){
                int v = GetVertNoSuccessor(tempAdjMat, tempSize);

                if(v == -1){
                    hasCycles = true;
                    break;
                }

                output.push_front(tempVerts[v].GetNode());

                //delete vertex from list and matrix
                if(v != (tempSize - 1)){

                    typename vector<GraphVertex<T>>::iterator it;
                    it = tempVerts.begin() + v;

                    tempVerts.erase(it);

                    for(int row = v; row < tempSize -1; row++){
                        for(int c= 0; c < tempSize; c++){
                            tempAdjMat[row][c] = tempAdjMat[row+1][c];
                        }
                    }
                    for(int col = v; col < tempSize -1; col++){
                        for(int r= 0; r < tempSize; r++){
                            tempAdjMat[r][col] = tempAdjMat[r][col + 1];
                        }
                    }
                }
                tempSize--;
            }

            //delete Temp Memory
            if(tempAdjMat != NULL){
                for(int i = 0; i < m_maxVerts; i++){
                    if(tempAdjMat[i] != NULL){
                        delete[] tempAdjMat[i];
                        tempAdjMat[i] = NULL;
                    }
                }
                delete[] tempAdjMat;
                tempAdjMat = NULL;
            }

            return !hasCycles;
        }

    private:
        vector<GraphVertex<T>> m_vertices;
        int m_maxVerts;

        char **m_adjMatrix;
        char *m_vertVisits;
};