 /*
 Function to display the top view of a binary Tree.
*/

/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

typedef pair<int,int> mypair;
map<int,mypair> m;

void get_top_view(node* root, int hd, map<int,mypair> &m, int height)
{
    if(root == NULL)
        return;
    
    if(m.find(hd)!= m.end())
    {
        if(m[hd].second >
 height)
        {
            m[hd].second = height;
            m[hd].first = root->data;            
        }
    }
    
    else
    {
        mypair p = make_pair(root->data,height);
        m[hd]=p;
    }
    get_top_view(root->left,hd-1,m,height+1);
    get_top_view(root->right,hd+1,m,height+1);
    
}


void top_view(node * root)
{
 
   int hd =0;
   int level =0;
   int height = 0;
   get_top_view(root,hd,m,height);
   map< int,mypair> :: iterator it;
   for(it =m.begin(); it!=m.end(); it++)
   {
        cout<< it->second.first<<" ";    
   }
}

