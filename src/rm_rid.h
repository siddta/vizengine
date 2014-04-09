//
// rm_rid.h
//
//   The Record Id interface
//

#ifndef RM_RID_H
#define RM_RID_H

// We separate the interface of RID from the rest of RM because some
// components will require the use of RID but not the rest of RM.

#include "redbase.h"

//
// PageNum: uniquely identifies a page in a file
//
typedef int PageNum;

//
// SlotNum: uniquely identifies a record in a page
//
typedef int SlotNum;


// Define the RM file header
struct RM_FileHeader {
  int recordSize;
  int numRecordsPerPage;
  int numPages;
  PageNum firstFreePage;
};

//
// RID: Record id interface
//
class RID {
  static const PageNum INVALID_PAGE = -1;
  static const SlotNum INVALID_SLOT = -1;
public:
    RID();                                         // Default constructor
    RID(PageNum pageNum, SlotNum slotNum);
    ~RID();                                        // Destructor

    RC GetPageNum(PageNum &pageNum) const;         // Return page number
    RC GetSlotNum(SlotNum &slotNum) const;         // Return slot number
    RC isValidRID() const;

private:
  PageNum page;
  SlotNum slot;
};

#define RM_INVALIDRID           (START_RM_WARN + 0)

#endif
