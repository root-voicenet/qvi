#ifndef TAXONOMYTERM_H
#define TAXONOMYTERM_H

#include <QString>
#include <QList>

class TaxonomyTerm
{
public:
    TaxonomyTerm(const QString& name, int tid, TaxonomyTerm *parent = 0);
    virtual ~TaxonomyTerm();
    void appendChild(TaxonomyTerm *child);

    TaxonomyTerm *child(int row);
    int childCount() const;
    int columnCount() const;
    int row() const;
    TaxonomyTerm *parent() { return m_parent; }

    int getTid() const { return m_tid; }
    QString getName() const { return m_name; }

    bool isChecked() const { return m_checked; }
    void setChecked( bool set ) { m_checked = set; }
protected:
    int m_tid;
    QString m_name;
    bool m_checked;
    QList<TaxonomyTerm *> m_childItems;
    TaxonomyTerm *m_parent;

};

#endif // TAXONOMYTERM_H
