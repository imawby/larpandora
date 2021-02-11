/**
 *  @file   larpandora/TestValidationAlgorithm.h
 *
 *  @brief  Header file for the test beam event validation algorithm.
 *
 *  $Log: $
 */
#ifndef TEST_VALIDATION_ALGORITHM_H
#define TEST_VALIDATION_ALGORITHM_H 1

#include "Pandora/Algorithm.h"

#include "larpandoracontent/LArHelpers/LArMCParticleHelper.h"

#include "larpandoracontent/LArMonitoring/EventValidationBaseAlgorithm.h"

#ifdef MONITORING
#include "PandoraMonitoringApi.h"
#endif

#include <map>

namespace lar_content
{

/**
 *  @brief  TestValidationAlgorithm class
 */
class TestValidationAlgorithm : public EventValidationBaseAlgorithm
{
public:
    /**
     *  @brief  Default constructor
     */
    TestValidationAlgorithm();

    /**
     *  @brief  Destructor
     */
    ~TestValidationAlgorithm();

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

    pandora::StatusCode ReadSettings(const pandora::TiXmlHandle xmlHandle);

    typedef std::vector<pandora::HitType> HitTypeVector;

    std::string m_instanceLabel;
};

 inline pandora::Algorithm *TestValidationAlgorithm::Factory::CreateAlgorithm() const
 {
   return new TestValidationAlgorithm();
 }

} // namespace lar_content

#endif // TEST_VALIDATION_ALGORITHM_H
