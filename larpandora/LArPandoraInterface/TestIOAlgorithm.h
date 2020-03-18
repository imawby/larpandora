/**
 *  @file   larpandora/LArPandoraInterface/TestIOAlgorithm.h
 *
 *  @brief  Header file for testing of Art IO.
 *
 *  $Log: $
 */

#ifndef LAR_TEST_IO_ALGORITHM_H
#define LAR_TEST_IO_ALGORITHM_H 1

#include "Pandora/Algorithm.h"

namespace lar_pandora
{

/**
 *  @brief  TestIOAlgorithm class
 */
class TestIOAlgorithm : public pandora::Algorithm
{
public:
    /**
     *  @brief  Default constructor
     */
    TestIOAlgorithm();

    virtual ~TestIOAlgorithm() = default;

    /**
     *  @brief  Factory class for instantiating algorithm
     */
    class Factory : public pandora::AlgorithmFactory
    {
    public:
        pandora::Algorithm *CreateAlgorithm() const;
    };

private:
    pandora::StatusCode Run();
    pandora::StatusCode ReadSettings(const pandora::TiXmlHandle xmlHandle);

    std::string m_instanceLabel;
};

inline pandora::Algorithm *TestIOAlgorithm::Factory::CreateAlgorithm() const
{
    return new TestIOAlgorithm();
}

} // namespace lar_content

#endif // #ifndef LAR_TEST_IO_ALGORITHM_H
