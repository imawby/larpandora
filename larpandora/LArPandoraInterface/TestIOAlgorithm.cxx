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
#include "larpandoracontent/LArControlFlow/MultiPandoraApi.h"

using namespace pandora;

namespace lar_pandora
{

TestIOAlgorithm::TestIOAlgorithm() :
    m_instanceLabel{""}
{
}

pandora::StatusCode TestIOAlgorithm::Run()
{
    std::cout << "TestIOAlgorithm::Run getting Pandora" << std::endl;
    const Pandora& pandora = this->GetPandora();
    std::cout << "TestIOAlgorithm::Run getting primary Pandora" << std::endl;
    const Pandora* primaryPandora = nullptr;
    try
    {
        primaryPandora = MultiPandoraApi::GetPrimaryPandoraInstance(&pandora);
    }
    catch(const StatusCodeException&)
    {   // This is the primary pandora instance
        primaryPandora = &this->GetPandora();
    }
    std::cout << "TestIOAlgorithm::Run Pandoras " << (&pandora) << " " << primaryPandora << std::endl;
    std::cout << "TestIOAlgorithm::Run with \'" << m_instanceLabel << "\'" << (&this->GetPandora()) << std::endl;
    const LArArtIOWrapper* artIOWrapper = LArPandora::GetArtIOWrapper(primaryPandora);
    std::cout << "TestIOAlgorithm::Run " << artIOWrapper << std::endl;
    LArPandoraOutput::Settings settings{artIOWrapper->GetPandoraOutputSettings()}; 
    settings.m_instanceLabel = m_instanceLabel;
    if (settings.m_shouldProduceAllOutcomes)
    {
        LArPandoraOutput::ProduceArtOutput(settings.m_pPrimaryPandora, settings,
                artIOWrapper->GetIdToHitMap(), artIOWrapper->GetEvent());
    }
    std::cout << "TestIOAlgorithm::Run " << settings.m_shouldProduceAllOutcomes << std::endl;
    settings.m_shouldProduceAllOutcomes = false;
    std::cout << "TestIOAlgorithm::Run produce output" << std::endl;
    LArPandoraOutput::ProduceArtOutput(settings.m_pPrimaryPandora, settings,
            artIOWrapper->GetIdToHitMap(), artIOWrapper->GetEvent()); 
    std::cout << "TestIOAlgorithm::Run produced" << std::endl;

    return STATUS_CODE_SUCCESS;
}

pandora::StatusCode TestIOAlgorithm::ReadSettings(const TiXmlHandle xmlHandle)
{
    std::cout << "TestIOAlgorithm::ReadSettings" << std::endl;
    PANDORA_RETURN_RESULT_IF_AND_IF(STATUS_CODE_SUCCESS, STATUS_CODE_NOT_FOUND,
            !=, XmlHelper::ReadValue(xmlHandle, "InstanceLabel", m_instanceLabel));
    std::cout << "TestIOAlgorithm::ReadSettings end" << std::endl;

    return STATUS_CODE_SUCCESS;
}

} // namespace lar_pandora

