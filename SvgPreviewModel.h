#pragma once

#include <QAbstractListModel>
#include <QList>
#include <QPixmap>
#include <QStringList>

class SvgPreviewModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit SvgPreviewModel(int previewSize, QObject* parent = nullptr);

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    int rowCount(const QModelIndex& parent) const override;

	// Call this to update the list of filenames. It reloads all files, even ones
	// that are already loaded.
	void setFiles(const QStringList& filenames);
	
	static const int FilenameRole = Qt::UserRole + 0;

private:
	int previewSize;
	
	struct Entry
	{
		QString filename;
		QPixmap preview;
	};
	
	QList<Entry> entries;
};
