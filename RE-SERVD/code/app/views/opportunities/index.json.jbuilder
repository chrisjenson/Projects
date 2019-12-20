# frozen_string_literal: true

json.array! @opportunities, partial: 'opportunities/opportunity', as: :opportunity
