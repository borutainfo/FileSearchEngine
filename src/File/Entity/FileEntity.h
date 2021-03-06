#ifndef FILESEARCHENGINE_FILEENTITY_H
#define FILESEARCHENGINE_FILEENTITY_H

#include "File/ValueObject/FileName.h"
#include "File/ValueObject/FileContent.h"

/**
 * @brief Entity for file storage in object way.
 * @struct FileEntity
 */
class FileEntity {
protected:
    FileName *fileName = nullptr;
    FileContent *fileContent = nullptr;

public:
    /**
    * @brief Method returns FileName VO.
    * @return FileName
    */
    FileName *getFileName() const;

    /**
     * @brief Method sets FileName VO in entity.
     * @param FileName *fileName
     */
    void setFileName(FileName *fileName);

    /**
    * @brief Method returns FileContent VO.
    * @return FileContent
    */
    FileContent *getFileContent() const;

    /**
    * @brief Method sets FileContent VO in entity.
    * @param FileContent *fileContent
    */
    void setFileContent(FileContent *fileContent);
};

#endif
