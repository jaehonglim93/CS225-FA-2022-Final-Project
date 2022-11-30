#include <kdtree.h>

KDTree::KDTree(vector<Node> nodes) {
  
}



typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::sort(vector<Node<Dim>> newPoints, unsigned left, unsigned right, int dimension) {
  if(left > right || newPoints.empty() || left < 0 || left >= newPoints.size()
    || right < 0 || right >= newPoints.size()) {
    return NULL;
  }

  unsigned k = (left + right) / 2;

  KDTreeNode* output = new KDTreeNode(QuickSelect(newPoints, left, right, dimension % Dim, k));
  output->left = sort(newPoints, left, k-1, (dimension+1)%Dim);
  output->right = sort(newPoints, k+1, right, (dimension+1)%Dim);
  size++;
  return output;
}

template <int Dim>
Node<Dim> KDTree<Dim>::QuickSelect(vector<Node<Dim>> newPoints, int left, int right, int dimension, int k) {
  if(left == right)
    return newPoints[left];
  
  int pivot = Partition(newPoints, left, right, dimension, k);

  if(pivot == k) {
    return newPoints[k];
  }
  if(k < pivot) {
    return QuickSelect(newPoints, left, pivot - 1, dimension, k);
  }
  return QuickSelect(newPoints, pivot + 1, right, dimension, k);
}

template <int Dim>
int KDTree<Dim>::Partition(vector<Node<Dim>> list, int left, int right, int dimension, int pivotIndex) {
  Node<Dim> pivotValue = list[pivotIndex];

  //swap list[pi] and list[right]
  Node<Dim> temp = list[pivotIndex];
  list[pivotIndex] = list[right];
  list[right] = temp;
  
  unsigned output = left;
  for(int i = left; i < right; i++) {
    if(smallerDimVal(list[i], pivotValue, dimension)) {
      temp = list[output];
      list[output] = list[i];
      list[i] = temp;
      output++;
    }
  }

  temp = list[output];
  list[output] = list[right];
  list[right] = temp;
  return output;
}