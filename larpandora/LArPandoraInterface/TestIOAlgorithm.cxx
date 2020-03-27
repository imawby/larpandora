/**
 *  @file   larpandora/LArPandoraInterface/TestIOAlgorithm.cc
 *
 *  @brief  Header file for testing of Art IO.
 *
 *  $Log: $
 */

#include "larpandora/LArPandoraInterface/TestIOAlgorithm.h"

#include "Pandora/AlgorithmHeaders.h"
#include "larpandora/LArPandoraInterface/LArArtIOWrapper.h"
#include "larpandora/LArPandoraInterface/LArPandora.h"
#include "larpandora/LArPandoraInterface/LArPandoraOutput.h"

using namespace pandora;

namespace lar_pandora
{

TestIOAlgorithm::TestIOAlgorithm() :
    m_instanceLabel{""}
{
}

pandora::StatusCode TestIOAlgorithm::Run()
{
    const LArArtIOWrapper* artIOWrapper = LArPandora::GetArtIOWrapper(&this->GetPandora());
    LArPandoraOutput::Settings settings{artIOWrapper->GetPandoraOutputSettings()}; 
    settings.m_instanceLabel = m_instanceLabel;
    if (settings.m_shouldProduceAllOutcomes)
    {
        LArPandoraOutput::ProduceArtOutput(settings.m_pPrimaryPandora, settings,
                artIOWrapper->GetIdToHitMap(), artIOWrapper->GetEvent());
    }
    settings.m_shouldProduceAllOutcomes = false;
    LArPandoraOutput::ProduceArtOutput(settings.m_pPrimaryPandora, settings,
            artIOWrapper->GetIdToHitMap(), artIOWrapper->GetEvent()); 

    return STATUS_CODE_SUCCESS;
}

pandora::StatusCode TestIOAlgorithm::ReadSettings(const TiXmlHandle xmlHandle)
{
    PANDORA_RETURN_RESULT_IF_AND_IF(STATUS_CODE_SUCCESS, STATUS_CODE_NOT_FOUND,
            !=, XmlHelper::ReadValue(xmlHandle, "InstanceLabel", m_instanceLabel));

    return STATUS_CODE_SUCCESS;
}

} // namespace lar_pandora

