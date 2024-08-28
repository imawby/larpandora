#ifndef NU_SLICE_ID_H
#define NU_SLICE_ID_H

namespace larpandora
{
  class NuSliceID
  {
  public:
      // Default constructor
      NuSliceID() = default;

      NuSliceID(const int pandoraNuSliceID, const int flashMatchNuSliceID);

      int GetPandoraNuSliceID() const;

      int GetFlashMatchNuSliceID() const;

  private:
      int m_pandoraNuSliceID = -1;
      int m_flashMatchNuSliceID = -1;
  };
}

#endif
