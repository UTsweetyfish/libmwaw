/* -*- Mode: C++; c-default-style: "k&r"; indent-tabs-mode: nil; tab-width: 2; c-basic-offset: 2 -*- */

/* libmwaw
* Version: MPL 2.0 / LGPLv2+
*
* The contents of this file are subject to the Mozilla Public License Version
* 2.0 (the "License"); you may not use this file except in compliance with
* the License or as specified alternatively below. You may obtain a copy of
* the License at http://www.mozilla.org/MPL/
*
* Software distributed under the License is distributed on an "AS IS" basis,
* WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
* for the specific language governing rights and limitations under the
* License.
*
* Major Contributor(s):
* Copyright (C) 2002 William Lachance (wrlach@gmail.com)
* Copyright (C) 2002,2004 Marc Maurer (uwog@uwog.net)
* Copyright (C) 2004-2006 Fridrich Strba (fridrich.strba@bluewin.ch)
* Copyright (C) 2006, 2007 Andrew Ziem
* Copyright (C) 2011, 2012 Alonso Laurent (alonso@loria.fr)
*
*
* All Rights Reserved.
*
* For minor contributions see the git repository.
*
* Alternatively, the contents of this file may be used under the terms of
* the GNU Lesser General Public License Version 2 or later (the "LGPLv2+"),
* in which case the provisions of the LGPLv2+ are applicable
* instead of those above.
*/

/*
 * Main parser of RagTime 5-6 document containing only a spreadsheet
 *
 */
#ifndef RAGTIME_5_SS_PARSER
#  define RAGTIME_5_SS_PARSER

#include <set>
#include <string>
#include <vector>

#include <librevenge/librevenge.h>

#include "MWAWEntry.hxx"
#include "MWAWPosition.hxx"

#include "MWAWParser.hxx"

namespace RagTime5SSParserInternal
{
struct State;
class SubDocument;
}

class RagTime5Document;

/** \brief the main class to parse a RagTime 5-6 file containing only a spreadsheet
 *
 *
 *
 */
class RagTime5SSParser final : public MWAWSpreadsheetParser
{
  friend class RagTime5SSParserInternal::SubDocument;
  friend class RagTime5Document;

public:
  //! constructor
  RagTime5SSParser(MWAWInputStreamPtr const &input, MWAWRSRCParserPtr const &rsrcParser, MWAWHeader *header);
  //! destructor
  ~RagTime5SSParser() final;

  //! checks if the document header is correct (or not)
  bool checkHeader(MWAWHeader *header, bool strict=false) final;

  // the main parse function
  void parse(librevenge::RVNGSpreadsheetInterface *documentInterface) final;

protected:
  //! inits all internal variables
  void init();

  //! creates the listener which will be associated to the document
  void createDocument(librevenge::RVNGSpreadsheetInterface *documentInterface);

  //
  // interface with the text parser
  //

  /** creates a document to send a footnote */
  void sendFootnote(int zoneId);

protected:

  //
  // data
  //
  //! the state
  std::shared_ptr<RagTime5SSParserInternal::State> m_state;

  //! the main document manager
  std::shared_ptr<RagTime5Document> m_document;
};
#endif
// vim: set filetype=cpp tabstop=2 shiftwidth=2 cindent autoindent smartindent noexpandtab:
