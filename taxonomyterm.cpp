#include "taxonomyterm.h"

TaxonomyTerm::TaxonomyTerm(const QString& name, int tid, TaxonomyTerm *parent)
    : m_name(name), m_tid(tid), m_parent(parent), m_checked(false)
{

}

TaxonomyTerm::~TaxonomyTerm()
{
    qDeleteAll(m_childItems);
}

void TaxonomyTerm::appendChild(TaxonomyTerm *child)
{
    m_childItems.append(child);
}

TaxonomyTerm *TaxonomyTerm::child(int row)
{
    return m_childItems.value(row);
}

int TaxonomyTerm::childCount() const
{
    return m_childItems.count();
}

int TaxonomyTerm::row() const
{
    if(m_parent)
        return m_parent->m_childItems.indexOf(const_cast<TaxonomyTerm*>(this));
    return 0;
}

