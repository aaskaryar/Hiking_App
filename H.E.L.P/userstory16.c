Qt::ItemFlags EditableSqlModel::flags(
const QModelIndex &index) const
{
Qt::ItemFlags flags = QSqlQueryModel::flags(index);
if (index.column() == 1 || index.column() == 2)
flags |= Qt::ItemIsEditable;
return flags;
}

bool EditableSqlModel::setData(const QModelIndex &index, const QVariant &value, int / role /)
{
if (index.column() < 1 || index.column() > 2)
return false;

QModelIndex primaryKeyIndex = QSqlQueryModel::index(index.row(), 0);
int id = data(primaryKeyIndex).toInt();

clear();

bool ok;
if (index.column() == 1) {
    ok = setFirstName(id, value.toString());
} else {
    ok = setLastName(id, value.toString());
}
refresh();
return ok;