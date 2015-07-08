#include "GameHandleLib.h"

//select the very widget from csb file by name
Node* seekFromRootByName(Node* _root, std::string& name)  
{
	if (!_root)
		return nullptr;
	if (_root->getName() == name)
		return _root;

	const auto& childArray = _root->getChildren();
	for (auto& child : childArray)
	{
		Node* pNode = dynamic_cast<Node*>(child); //?   or static_cast?
		if (pNode)
		{
			Node* res = seekFromRootByName(pNode, name);
			if (res)
				return res;
		}
	}

	return nullptr;
}