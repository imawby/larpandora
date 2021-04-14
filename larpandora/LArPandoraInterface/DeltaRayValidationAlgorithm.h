/**
 *  @file   larpandoracontent/LArMonitoring/DeltaRayValidationAlgorithm.h
 *
 *  @brief  Header file for the delta ray event validation algorithm.
 *
 *  $Log: $
 */
#ifndef DELTA_RAY_VALIDATION_ALGORITHM_H
#define DELTA_RAY_VALIDATION_ALGORITHM_H 1

#include "Pandora/Algorithm.h"

#include "larpandoracontent/LArHelpers/LArMCParticleHelper.h"
#include "larpandoracontent/LArHelpers/LArMuonLeadingHelper.h"

#include "larpandoracontent/LArMonitoring/EventValidationBaseAlgorithm.h"

#ifdef MONITORING
#include "PandoraMonitoringApi.h"
#endif

#include <map>

namespace lar_content
{

/**
 *  @brief  DeltaRayValidationAlgorithm class
 */
class DeltaRayValidationAlgorithm: public EventValidationBaseAlgorithm
{
public:
    /**
     *  @brief  Default constructor
     */
    DeltaRayValidationAlgorithm();

    /**
     *  @brief  Destructor
     */
    ~DeltaRayValidationAlgorithm();

    /**
     *  @brief  Factory class for instantiating algorithm
     */
    class Factory : public pandora::AlgorithmFactory
    {
    public:
      pandora::Algorithm *CreateAlgorithm() const;
    };

private:
    /**
     *  @brief  Fill the validation info containers
     *
     *  @param  pMCParticleList the address of the mc particle list
     *  @param  pCaloHitList the address of the calo hit list
     *  @param  pPfoList the address of the pfo list
     *  @param  validationInfo to receive the validation info
     */
    void FillValidationInfo(const pandora::MCParticleList *const pMCParticleList, const pandora::CaloHitList *const pCaloHitList,
        const pandora::PfoList *const pPfoList, ValidationInfo &validationInfo) const;

    void DetermineIncorrectlyReconstructedMuons(const pandora::MCParticleList *const pMCParticleList, const pandora::CaloHitList *const pCaloHitList,
        const pandora::PfoList *const pPfoList, pandora::MCParticleList &incorrectlyReconstructedCosmicRays) const;
    
    void FillDeltaRayValidationInfo(const pandora::MCParticleList *const pMCParticleList, const pandora::CaloHitList *const pCaloHitList,
        const pandora::PfoList *const pPfoList, ValidationInfo &validationInfo) const;

    void WriteOutput(const ValidationInfo &validationInfo) const;

    typedef std::unordered_map<const pandora::ParticleFlowObject*, unsigned int> PfoToIdMap;

    /**
     *  @brief  Print matching information in a provided validation info object, and write information to tree if configured to do so
     *
     *  @param  validationInfo the validation info
     *  @param  useInterpretedMatching whether to use the interpreted (rather than raw) matching information
     *  @param  printToScreen whether to print the information to screen
     *  @param  fillTree whether to write the information to tree
     */
    void ProcessOutput(const ValidationInfo &validationInfo, const bool useInterpretedMatching, const bool printToScreen, const bool fillTree) const;

    void GetRecoMuonHits(const pandora::MCParticleList *const pMCParticleList, const pandora::CaloHitList *const pCaloHitList,
        const pandora::PfoList *const pPfoList, pandora::CaloHitList &recoMuonHitList) const;

    void FillContaminationHitsDistance(const pandora::CaloHitList &contaminationHits, const pandora::CaloHitList &leadingMCHits,
        pandora::FloatVector &bestMatchContaminationHitsDistance) const;

    void GetHitsOfType(const pandora::CaloHitList &inputList, const pandora::HitType &hitType, pandora::CaloHitList &outputList) const;

    pandora::StatusCode ReadSettings(const pandora::TiXmlHandle xmlHandle);


    typedef std::vector<pandora::HitType> HitTypeVector;

    LArMCParticleHelper::PrimaryParameters      m_cosmicRayValidationParameters;    
    LArMuonLeadingHelper::ValidationParameters  m_validationParameters;

    pandora::MCParticleList m_correctlyReconstructedCosmicRays;

    bool m_removeRecoMuonHits;    
    bool m_deltaRayMode;
    bool m_michelMode;
    int m_muonsToSkip;
    bool m_visualize;
    bool m_ignoreIncorrectMuons;
    bool m_writeRawMatchesToTree;

    std::string m_instanceLabel;
};

 inline pandora::Algorithm *DeltaRayValidationAlgorithm::Factory::CreateAlgorithm() const
 {
   return new DeltaRayValidationAlgorithm();
 }

} // namespace lar_content

#endif // DELTA_RAY_VALIDATION_ALGORITHM_H
