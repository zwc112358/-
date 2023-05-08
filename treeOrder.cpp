
#include <iostream>
#include <queue>
#include <vector>
template<class T>
struct TreeNode
{
    T data;
    TreeNode<T>* leftChild;
    TreeNode<T>* rightChild;
    TreeNode()
    {
        leftChild = rightChild = nullptr;
    }
    TreeNode(T& val, TreeNode<T>* left = nullptr, TreeNode<T>* right = nullptr)
    {
        data = val;
        leftChild = left;
        rightChild = right;
    }
};

template<class T>
class tree
{
public:
    tree() { root = new TreeNode<T>;}
    ~tree() { destroy(root); }

    void destroy(TreeNode<T>* node)
    {
        if (node != nullptr)
        {
            destroy(node->leftChild);
            destroy(node->rightChild);
            delete node;
            node = nullptr;
        }
    }
    TreeNode<T>* getNode() { return root; }

    void preOrder(TreeNode<T>* rootNode)
    {
        if (rootNode != nullptr)
        {
            std::cout << rootNode->data << "  ";
            preOrder(rootNode->leftChild);
            preOrder(rootNode->rightChild);
        }
    }

    void inOrder(TreeNode<T>* rootNode)
    {
        if (rootNode != nullptr)
        {
            inOrder(rootNode->leftChild);
            std::cout << rootNode->data << "  ";
            inOrder(rootNode->rightChild);
        }
    }

    void postOrder(TreeNode<T>* rootNode)
    {
        if (rootNode != nullptr)
        {
            postOrder(rootNode->leftChild);
            postOrder(rootNode->rightChild);
            std::cout << rootNode->data << "  ";
        }
    }


    void zhiOrderPrint(TreeNode<T>* rootNode)
    {
        if (rootNode == nullptr)
        {
            return;
        }

        std::queue<TreeNode<T>*> queData;
        queData.push(rootNode);
        std::vector<std::vector<T>> vecData;
        
        while (!queData.empty())
        {
            std::vector<T> temp;
            for (int i = queData.size(); i > 0; --i)
            {
                TreeNode<T>* node = queData.front();
                queData.pop();
                temp.push_back(node->data);
                if (node->leftChild != nullptr)
                    queData.push(node->leftChild);
                if (node->rightChild != nullptr)
                    queData.push(node->rightChild);
            }
            if ((vecData.size() & 1) == 1)
                reverse(temp.begin(), temp.end());
            vecData.push_back(temp);
        }
        std::cout << "之字顺序打印：  ";
        printVector(vecData);
    }


    void reverseZhiOrderPrint(TreeNode<T>* rootNode)
    {
        if (rootNode == nullptr)
        {
            return;
        }

        std::queue<TreeNode<T>*> queData;
        queData.push(rootNode);
        std::vector<std::vector<T>> vecData;

        while (!queData.empty())
        {
            std::vector<T> temp;
            for (int i = queData.size(); i > 0; --i)
            {
                TreeNode<T>* node = queData.front();
                queData.pop();
                temp.push_back(node->data);
                if (node->leftChild != nullptr)
                    queData.push(node->leftChild);
                if (node->rightChild != nullptr)
                    queData.push(node->rightChild);
            }
            if ((vecData.size() & 1) == 0)
                reverse(temp.begin(), temp.end());
            vecData.push_back(temp);
        }
        std::cout << "反之字顺序打印：  ";
        printVector(vecData);
    }


    void orderPrint(TreeNode<T>* rootNode)
    {
        if (rootNode == nullptr)
        {
            return;
        }

        std::queue<TreeNode<T>*> queData;
        queData.push(rootNode);
        std::vector<std::vector<T>> vecData;

        while (!queData.empty())
        {
            std::vector<T> temp;
            while (queData.size() != 0)
            {
                TreeNode<T>* node = queData.front();
                queData.pop();
                temp.push_back(node->data);
                if (node->leftChild != nullptr)
                    queData.push(node->leftChild);
                if (node->rightChild != nullptr)
                    queData.push(node->rightChild);
            }
            vecData.push_back(temp);
        }
        std::cout << "顺序打印：  ";
        printVector(vecData);
    }

    void printVector(std::vector<std::vector<T>>& vecData)
    {
        for (auto a : vecData)
        {
            for (auto b : a)
            {
                std::cout << b << "  ";
            }
        }
        std::cout << std::endl;
    }
private:
    TreeNode<T>* root;
};


int main()
{
    //create int tree
    tree<int> treeIntRoot;
    auto nodeRoot = treeIntRoot.getNode();
    nodeRoot->data = 5;

    int value = 7;
    TreeNode<int>* node1Left = new TreeNode<int>(value);
    value = 10;
    TreeNode<int>* node1Right = new TreeNode<int>(value);
    nodeRoot->leftChild = node1Left;
    nodeRoot->rightChild = node1Right;

    value = 6;
    TreeNode<int>* node1Left2Left = new TreeNode<int>(value);
    value = 2;
    TreeNode<int>* node1Left2Right = new TreeNode<int>(value);
    node1Left->leftChild = node1Left2Left;
    node1Left->rightChild = node1Left2Right;

    value = 3;
    TreeNode<int>* node1Right2Left = new TreeNode<int>(value);
    value = 4;
    TreeNode<int>* node1Right2Right = new TreeNode<int>(value);
    node1Right->leftChild = node1Right2Left;
    node1Right->rightChild = node1Right2Right;

    //前中后序遍历
    std::cout << "pre order:   ";
    treeIntRoot.preOrder(nodeRoot);
    std::cout << std::endl << "in order:   ";
    treeIntRoot.inOrder(nodeRoot);
    std::cout << std::endl << "post order:   ";
    treeIntRoot.postOrder(nodeRoot);
    std::cout << std::endl;



    //顺序打印
    treeIntRoot.orderPrint(nodeRoot);


    //之字型打印
    treeIntRoot.zhiOrderPrint(nodeRoot);


    //反之字型打印
    treeIntRoot.reverseZhiOrderPrint(nodeRoot);





    //create string tree
    tree<std::string> treeStringRoot;
    auto nodeStringRoot = treeStringRoot.getNode();
    nodeStringRoot->data = "root";

    std::string valueString = "1left";
    TreeNode<std::string>* nodeString1Left = new TreeNode<std::string>(valueString);
    valueString = "1right";
    TreeNode<std::string>* nodeString1Right = new TreeNode<std::string>(valueString);
    nodeStringRoot->leftChild = nodeString1Left;
    nodeStringRoot->rightChild = nodeString1Right;

    valueString = "1left2left";
    TreeNode<std::string>* nodeString1Left2Left = new TreeNode<std::string>(valueString);
    valueString = "1left2right";
    TreeNode<std::string>* nodeString1Left2Right = new TreeNode<std::string>(valueString);
    nodeString1Left->leftChild = nodeString1Left2Left;
    nodeString1Left->rightChild = nodeString1Left2Right;

    valueString = "1right2left";
    TreeNode<std::string>* nodeString1Right2Left = new TreeNode<std::string>(valueString);
    valueString = "1right2right";
    TreeNode<std::string>* nodeString1Right2Right = new TreeNode<std::string>(valueString);
    nodeString1Right->leftChild = nodeString1Right2Left;
    nodeString1Right->rightChild = nodeString1Right2Right;

    //前中后序遍历
    std::cout << "pre order:   ";
    treeStringRoot.preOrder(nodeStringRoot);
    std::cout << std::endl << "in order:   ";
    treeStringRoot.inOrder(nodeStringRoot);
    std::cout << std::endl << "post order:   ";
    treeStringRoot.postOrder(nodeStringRoot);
    std::cout << std::endl;



    //顺序打印
    treeStringRoot.orderPrint(nodeStringRoot);


    //之字型打印
    treeStringRoot.zhiOrderPrint(nodeStringRoot);


    //反之字型打印
    treeStringRoot.reverseZhiOrderPrint(nodeStringRoot);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
