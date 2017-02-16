struct ListNode{
	int m_nValue;
	ListNode*m_pNext;
};

void DeleteNode(ListNode*pListHead, ListNode*pToBeDeleted)
{
	if (pListHead == nullptr||pToBeDeleted==nullptr)
		return;
	if (pToBeDeleted->m_pNext = nullptr)
	{
		ListNode*tmp = pListHead;
		if (tmp == pToBeDeleted)
		{
			delete tmp;
			tmp = nullptr;
		}
		else
		{
			while (tmp->m_pNext != pToBeDeleted)
			{
				tmp = tmp->m_pNext;
			}
			delete pToBeDeleted;
			pToBeDeleted = nullptr;
			tmp->m_pNext = nullptr;
		}

	}
	else
	{
		ListNode*tmp = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = tmp->m_nValue;
		pToBeDeleted->m_pNext = tmp->m_pNext;
		delete tmp;
		tmp = nullptr;
	}
}


