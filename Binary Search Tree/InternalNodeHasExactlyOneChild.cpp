/*
Problem Statement-
Check wheather in given preorder travrersal of BST all internal nodes has exactly one child or not
Solution Approach-
Since all the descendants of a node must either be larger or smaller than the node. We can do following for every node in a loop.
1. Find the next preorder successor (or descendant) of the node.
2. Find the last preorder successor (last element in pre[]) of the node.
3. If both successors are less than the current node, or both successors are greater than the current node, then continue.Else,return false

*/

bool hasOnlyOneChild(int pre[], int size)
{
    int nextDiff, lastDiff;
 
    for (int i=0; i<size-1; i++)
    {
        nextDiff = pre[i] - pre[i+1];
        lastDiff = pre[i] - pre[size-1];
        if (nextDiff*lastDiff < 0)
            return false;;
    }
    return true;
}
