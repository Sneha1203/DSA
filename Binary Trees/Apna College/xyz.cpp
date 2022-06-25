class Solution
{
   public static Node buildTree(int inorder[], int preorder[], int n)
   {
       // code here 
       HashMap<Integer,Integer> map = new HashMap<>();
       
       for(int i=0;i<inorder.length;i++)
         map.put(inorder[i],i);  // storing in the map t get the value of the root in the inorder so thatleft and right element can be tracked
          
       Node root = constructTree(preorder,0,preorder.length-1,inorder,0,inorder.length-1,map);
       return root;
   }
    static Node constructTree(int[] preorder,int preStart,int preEnd,int[] inorder,int inStart,int inEnd,HashMap<Integer,Integer> map){
       // if by chance the prestart>preend it means that there is no preorder root left thus null should be there same in case of instart
       if(preStart>preEnd || inStart>inEnd) return null;
       // making a new node with preorder[prestart]
       Node root=new Node(preorder[preStart]);
       // finding the root in the map to count how many left element are present in it
       int inRoot=map.get(root.data);
       // it counts that inRoot is in which index thus subtract that index from start we will get the left element
       int numleft=inRoot-inStart;
       // while backtrcking root.left part will be filled
       root.left=constructTree(preorder,preStart+1,preStart+numleft,inorder,inStart,inRoot-1,map);
       // while backtrcking root.right part will be filled
       root.right=constructTree(preorder,preStart+numleft+1,preEnd,inorder,inRoot+1,inEnd,map);
       return root;
   }
}