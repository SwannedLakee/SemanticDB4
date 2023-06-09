//
// Semantic DB 4
// Created 2023/5/16
// Updated 2023/5/16
// Author Garry Morrison
// License GPL v3
//

#pragma once

#include "../Sequence/Sequence.h"
#include "../Sequence/Ket.h"
#include "../Function/misc.h"
#include "../Context/ContextList.h"
#include "../Sequence/BaseSequence.h"
#include "../Operator/BaseOperator.h"
#include "../CompoundConstant/CompoundConstant.h"
#include "../Operator/SimpleOperator.h"
#include <algorithm>

struct TemplateMachine {
	bool has_daughters = false;
	ulong the_node_idx = 0;
	ulong text_idx = 0;  // I don't remember what this parameter is for...
	std::vector<std::string> text_seq_vec;
	std::vector<ulong> head_seq_vec;
	std::vector<ulong> value_seq_vec;
	std::string compressed_text;
	int structure_word_count = 0;
	std::vector<int> range_stars;
	std::vector<int> range_non_stars;
};


std::size_t int_vector_to_hash(const std::vector<ulong>& vec);
Superposition op_TM_ngram_partition(const Sequence& input_seq, ContextList& context, const std::vector<std::shared_ptr<CompoundConstant> >& parameters);

Ket op_TM_sequence_hash(const Sequence& input_seq);
Ket op_TM_ket_hash(const Ket& k);
Ket op_TM_compress_stars(const Ket& k);

Ket op_TM_extract_text(const Sequence& input_seq, const Sequence& one);

// Maybe change type to function, not compound operator?
Ket op_TM_learn_sentences(const Sequence& input_seq, ContextList& context, const std::vector<std::shared_ptr<CompoundConstant> >& parameters);

