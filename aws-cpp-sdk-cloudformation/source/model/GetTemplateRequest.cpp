﻿/*
* Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/cloudformation/model/GetTemplateRequest.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

using namespace Aws::CloudFormation::Model;
using namespace Aws::Utils;

GetTemplateRequest::GetTemplateRequest() : 
    m_stackNameHasBeenSet(false),
    m_changeSetNameHasBeenSet(false),
    m_templateStage(TemplateStage::NOT_SET),
    m_templateStageHasBeenSet(false)
{
}

Aws::String GetTemplateRequest::SerializePayload() const
{
  Aws::StringStream ss;
  ss << "Action=GetTemplate&";
  if(m_stackNameHasBeenSet)
  {
    ss << "StackName=" << StringUtils::URLEncode(m_stackName.c_str()) << "&";
  }

  if(m_changeSetNameHasBeenSet)
  {
    ss << "ChangeSetName=" << StringUtils::URLEncode(m_changeSetName.c_str()) << "&";
  }

  if(m_templateStageHasBeenSet)
  {
    ss << "TemplateStage=" << TemplateStageMapper::GetNameForTemplateStage(m_templateStage) << "&";
  }

  ss << "Version=2010-05-15";
  return ss.str();
}

